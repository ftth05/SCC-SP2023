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
    // the number of columns in matrix D.
    //int n = D.size[0].size();
    num_features = n;
    S.resize(n*n);
    float gamma = 1.0 / n;
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
        int n = sqrt(D.size());
        num_features = n;
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
    
};

// Define the Mink class, which inherits from Euclid
class Mink : public Euclid {
public:
    void dist(std::vector<float>& X) {
        int n = sqrt(D.size());
        num_features = n;
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
        cout << n <<"Minkowski distance computed" << endl;
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
    std::vector<float> known_drug(299);
    for (int i = 0; i < 299; i++) {
        known_drug_file >> known_drug[i];
    }

    // Close the input files
    in_file.close();
    known_drug_file.close();

    // 1e_1 Create two objects of class Mink
    Mink MK1;

    // Compute the distance vector D using MK1
    for (int i = 0; i < n_rows; i++) {
        MK1.dist(A[i]);
    }
/*
    // Compute the similarity vector S using an ancestor class method
    MK1.num_features = n_cols;
    //MK1.sim

    // Create object MK2 of class Mink
    Mink MK2(num_features, A.size());

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
    */

}