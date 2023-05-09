#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class BaseCadd {
public:
    int num_features;
    vector<float> S;
    
    
    void sim(vector<float>& D, int num_features) {
        this->num_features = num_features;
        S.resize(D.size());
        float gamma = 1.0 / num_features;
        for (int i = 0; i < D.size(); i++) {
            S[i] = exp(-D[i] * gamma);
        }
    }
};

class Euclid : public BaseCadd {
public:
    vector<float> D;
    
    void dist(vector<float>& X, vector<float>& Y) {
        D.resize(X.size());
        float temp = 0;
        for (int i = 0; i < X.size(); i++) {
            temp += pow((X[i] - Y[i]), 2);
        }
        D[0] = sqrt(temp);
    }
};

class Mink : public Euclid {
public:
    void dist(vector<float>& X, vector<float>& Y) {
        D.resize(X.size());
        float temp = 0;
        for (int i = 0; i < X.size(); i++) {
            temp += pow(abs(X[i] - Y[i]), 3);
        }
        D[0] = pow(temp, 1.0/3);
    }
};

int main() {

    ifstream file("bioresponse_descriptors_matrix.txt");
    int num_rows = 0;
    int num_cols = 0;
    std::string line;
    while (std::getline(file, line)) {
        num_rows++;
        num_cols = std::count(line.begin(), line.end(), ' ') + 1;
        }
    vector<vector<float> > A(num_rows, vector<float>(num_cols));
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            file >> A[i][j];
        }
    }
    file.close();

    cout << num_rows << " " << num_cols << endl;
    
    ifstream file2("known_drug.txt");
    vector<float> B(num_cols);
    for (int j = 0; j < num_cols; j++) {
        file2 >> B[j];
    }
    file2.close();

// Compute similarity vectors
    Mink MK1;
    MK1.dist(A[0], B);
    MK1.sim(MK1.D, num_cols);
    
    Euclid MK2;
    MK2.dist(A[0], B);
    MK2.sim(MK2.D, num_cols);

    // Write output to file
    ofstream outfile1("result1.txt");
    for (int i = 0; i < num_rows; i++) {
        outfile1 << MK1.S[i] << endl;
    }
    outfile1.close();
    
    ofstream outfile2("result2.txt");
    for (int i = 0; i < num_rows; i++) {
        outfile2 << MK2.S[i] << endl;
    }
    outfile2.close();


    // // Print out the index for the top 10 most similar entries
    std::ofstream sorted1_file("sorted_result1.txt");
    std::ofstream sorted2_file("sorted_result2.txt");
    for (int i = 0; i < 10; i++) {
        int index1 = std::find(MK1.S.begin(), MK1.S.end(), MK1.S[i]) - MK1.S.begin();
        int index2 = std::find(MK2.S.begin(), MK2.S.end(), MK2.S[i]) - MK2.S.begin();
        sorted1_file << index1 << std::endl;
        sorted2_file << index2 << std::endl;
    }
    sorted1_file.close();
    sorted2_file.close();

    
    return 0;

}