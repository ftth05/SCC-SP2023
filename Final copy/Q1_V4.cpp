#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

// Define the BaseCadd class
class BaseCadd {
public:
    int num_features;
    std::vector<float> S;
    void sim(std::vector<float>& D) {
    int n = sqrt(D.size()); // assuming D is a square matrix
    S.resize(n*n);
    float gamma = 1.0 / num_features;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int idx = i*n + j;
            S[idx] = exp(-D[idx] * gamma);
            }
        }
    }
};

// Define the Euclid class, which inherits from BaseCadd
class Euclid : public BaseCadd {
public:
    std::vector<float> D;
    void dist(std::vector<float>& X) {
        int n = X.size() / num_features;
        D.resize(n*n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                float sum = 0;
                for (int k = 0; k < num_features; k++) {
                    float diff = X[i*num_features + k] - X[j*num_features + k];
                    sum += diff * diff;
                }
                D[i*n + j] = sqrt(sum);
            }
        }
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
    void dist(std::vector<float>& X) {
        int n = X.size() / num_features;
        D.resize(n*n);
        float p = 3;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                float sum = 0;
                for (int k = 0; k < num_features; k++) {
                    float diff = X[i*num_features + k] - X[j*num_features + k];
                    sum += pow(fabs(diff), p);
                }
                D[i*n + j] = pow(sum, 1.0/p);
            }
        }
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
    //in_file.close();
    //known_drug_file.close();

    // 1e_1 Create two objects of class Mink
    // Create MK1 and MK2 objects of class Mink
    Mink MK1(num_features);
    Mink MK2(num_features);

    // Compute distance vector D using Minkowski distance metric for MK1
    for (int i = 0; i < num_rows; i++) {
        float dist = MK1.dist(A[i], known_drug);
        MK1.D.push_back(dist);
    }

    // Compute similarity vector S using ancestor class method for MK1
    MK1.sim(1.0 / num_features);

    // Compute distance vector D using Euclidean distance metric for MK2
    for (int i = 0; i < num_rows; i++) {
        float dist = MK2.dist(A[i], known_drug);
        MK2.D.push_back(dist);
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