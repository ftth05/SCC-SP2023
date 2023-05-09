#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

// Define the BaseCadd class
class BaseCadd {
public:
    int num_features;
    std::vector<float> S;
    virtual void sim(float *D, int n_rows) {}
};

// Define the Euclid class, which inherits from BaseCadd
class Euclid : public BaseCadd {
public:
    std::vector<float> D;
    void dist(float *x, float *y, int n_features) {
        float d = 0.0;
        for (int i = 0; i < n_features; i++) {
            float diff = x[i] - y[i];
            d += diff * diff;
        }
        D.push_back(sqrt(d));
    }
    void sim(float *D, int n_rows) {
        float gamma = 1.0 / num_features;
        for (int i = 0; i < n_rows; i++) {
            S.push_back(exp(-D[i] * gamma));
        }
    }
};

// Define the Mink class, which inherits from Euclid
class Mink : public Euclid {
public:
    void dist(float *x, float *y, int n_features) {
        float p = 3.0;
        float d = 0.0;
        for (int i = 0; i < n_features; i++) {
            d += pow(fabs(x[i] - y[i]), p);
        }
        D.push_back(pow(d, 1.0 / p));
    }
};

int main() {
    // Open the input files
    std::ifstream in_file("bioresponse_descriptors_matrix.txt");
    std::ifstream known_drug_file("known_drug.txt");

    // Read the number of rows and columns from the input file
    int n_rows, n_cols;
    in_file >> n_rows >> n_cols;

    // Allocate memory for the 2D array A
    float **A = new float *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        A[i] = new float[n_cols];
    }

    // Read the data from the input file into the 2D array A
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            in_file >> A[i][j];
        }
    }

    // Read the data for the known drug from the input file
    std::vector<float> known_drug(n_cols);
    for (int i = 0; i < n_cols; i++) {
        known_drug_file >> known_drug[i];
    }

    // Close the input files
    in_file.close();
    known_drug_file.close();

    // 1e_1 Create two objects of class Mink
    Mink MK1, MK2;

    // Compute the distance vector D using MK1
    for (int i = 0; i < n_rows; i++) {
        MK1.dist(A[i], known_drug.data(), n_cols);
    }

    // Compute the similarity vector S using an ancestor class method
    MK1.num_features = n_cols;
    MK1.sim


    // Create object MK2 of class Mink
    //Mink MK2(num_features, A.size());

    // 1e_2 Compute distance vector D using Euclidean distance metric
    for (int i = 0; i < A.size(); i++) {
        float dist = MK2.dist(A[i], B[0]);
        MK2.D[i] = dist;
    }

    // 1f Write similarity vector S computed by MK1 to result1.txt
    ofstream out1("result1.txt");
    if (out1.is_open()) {
        for (int i = 0; i < MK1.S.size(); i++) {
            out1 << MK1.S[i] << endl;
        }
        out1.close();
    }

    // Write similarity vector S computed by MK2 to result2.txt
    ofstream out2("result2.txt");
    if (out2.is_open()) {
        for (int i = 0; i < MK2.S.size(); i++) {
            out2 << MK2.S[i] << endl;
        }
        out2.close();
    }
}