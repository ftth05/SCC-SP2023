#include <vector>
#include <cmath>

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
