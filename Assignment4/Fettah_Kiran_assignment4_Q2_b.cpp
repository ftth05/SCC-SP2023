// Name: Fettah Kiran
// UHID: 1678975
// HW4




/*


2b:) Implement the function in code, i.e, write a C++ function that returns y given x as input or argument. 

Test the function for x at 0, 3 , 20

*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Function to read data from a CSV file into a vector of pairs
vector<pair<double, double> > readDataFromFile(const string& filename) {
    vector<pair<double, double> > data;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            double x, y;
            char comma;
            if (iss >> x >> comma >> y) {
                data.push_back(make_pair(x, y));
            }
        }
        file.close();
    } else {
        cout << "Failed to open file: " << filename << endl;
    }
    return data;
}

void computeLinearFunction(const vector<pair<double, double> >& data, double x) {
    double sum_x = 0.0;
    double sum_y = 0.0;
    double sum_xy = 0.0;
    double sum_x2 = 0.0;

    for (const auto& pair : data) {
        double x_i = pair.first;
        double y_i = pair.second;
        sum_x += x_i;
        sum_y += y_i;
        sum_xy += x_i * y_i;
        sum_x2 += x_i * x_i;
    }

    double n = data.size();
    double mean_x = sum_x / n;
    double mean_y = sum_y / n;
    double slope = (sum_xy - n * mean_x * mean_y) / (sum_x2 - n * mean_x * mean_x);
    double intercept = mean_y - slope * mean_x;

    double y = slope * x + intercept;
    cout << "For x = " << x << ", y = " << y << endl;
}

int main() {
    // Input
    string filename = "X_and_Y.csv";  // File containing data

    // Read data from file
    vector<pair<double, double> > data = readDataFromFile(filename);

    // Compute slope-intercept form components and print linear function
    if (!data.empty()) {
        computeLinearFunction(data, 0);  // Compute and print y for x = 0
        computeLinearFunction(data, 3);  // Compute and print y for x = 3
        computeLinearFunction(data, 20);  // Compute and print y for x = 20
    }

    return 0;
}
