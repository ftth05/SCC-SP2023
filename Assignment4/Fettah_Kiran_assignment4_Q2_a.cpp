// Name: Fettah Kiran
// UHID: 1678975
// HW4




/*

Using data from the table (table needs to be read into the program). Write a program that does the following:

2a:) computes the slope-intercept form components and prints out the linear function given in the table. 

for reference see https://en.wikipedia.org/wiki/Linear_equation#Slope%E2%80%93intercept_form_or_Gradient-intercept_form

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Function to read data from a CSV file into a vector of pairs
vector<pair<double, double > > readDataFromFile(const string& filename) {
    vector<pair<double, double > > data;
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

// Function to compute the slope-intercept form components for a linear function
void computeLinearFunction(const vector<pair< double, double > >& data) {
    double sum_x = 0.0;
    double sum_y = 0.0;
    double sum_xy = 0.0;
    double sum_x2 = 0.0;

    for (const auto& pair : data) {
        double x = pair.first;
        double y = pair.second;
        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_x2 += x * x;
    }

    double n = data.size();
    double mean_x = sum_x / n;
    double mean_y = sum_y / n;
    double slope = (sum_xy - n * mean_x * mean_y) / (sum_x2 - n * mean_x * mean_x);
    double intercept = mean_y - slope * mean_x;

    cout << "Linear function: y = " << slope << " * x + " << intercept << endl;
}

int main() {
    // Input
    string filename = "X_and_Y.csv";  

    // Read data from file
    vector<pair<double, double > > data = readDataFromFile(filename);

    // Compute slope-intercept form components and print linear function
    if (!data.empty()) {
        computeLinearFunction(data);
    }

    return 0;
}
