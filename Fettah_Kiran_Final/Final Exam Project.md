Final Exam Project
Opened: Wednesday, April 19, 2023, 12:00 AM
Due: Wednesday, April 26, 2023, 5:00 PM
Note: You would need a passing score in this project to be considered for a badge or certificate in the course, it encapsulates all the concepts you have learned so far.  

Submission Instructions
Please provide compressed(zip, tar.gz, etc.) final solutions to the parts below. There is no need to include the input files. Along with each set of solutions, please include a README.txt with execution/compilation instructions for your code.


Final Project
The goal of this exercise is to rank entries from an arbitrary chemical database of drug-like chemicals in terms of similarity with a known drug for treating some ailment. 185 numerical features/values are computed for each chemical, and stored in the database file. Your task at a high level is to rank the database by similarity to this known drug in the contest of this feature space and recommend the top 10 ten most similar entries for purchase and further testing.

Exercise:
1) Write C/C++ code that does the following:
1a)
provide a base class called BaseCadd. BaseCadd will be our fancy name for a class that does BASic Computer-Aided Drug Design.
The members include:
an int called num_features,
an STL vector of floats called "S". Note vector "S" will be used for storing similarity values between chemical compounds.
Also, BaseCadd should include a method/function called "sim" for computing the similarity vector S, given the distance vector D, and the number of features.
using the approximation
Sij = exp(-Dij * gamma), where one heuristic for choosing gamma is 1.00 / num_features or the number of columns in matrix A.


1b)
provide a descendant class called Euclid. It will inherit from the base class BaseCadd:
it members include:
an STL vector of floats called D
a method for computing the Euclidean distance metric called "dist"
the Euclidean distance metric is a metric where the distance "dij" between observations  i and j , and is given by
dij= sum((Xi - Xj)^2)^(1/2)

or

dij= sum((Xi - Xj)^2.0) ^ 0.50

Wikipedia reference: https://en.wikipedia.org/wiki/Euclidean_distance

1c)
provide a descendant class called Mink. It will inherit from the class Euclid:
it members includes:
a method for computing the Minkowski distance metric called "dist"
the Minkwoski distance metric is a metric where the distance "dij" between observation i and j , and is given by
dij= sum((Xi - Xj)^p)^(1/p), with p set at 3

Wikipedia reference: https://en.wikipedia.org/wiki/Minkowski_distance
Note, this method will override the inherited dist method if called directly.


1d)
Read in the biological response feature dataset from the file named " bioresponse_descriptors_matrix.txt". Store the data in 2D array of floats or matrix called A. Note the number of columns. Also, read in the biological response feature data for the known drug, which is in the in file "known_drug.txt".

1e)
1e)(1)
Create two objects of class Mink, call them MK1 and MK2.
Use MK1, and its dist method to compute the distance vector D of Minkowski distances between every row in "bioresponse_descriptors_matrix.txt" vs the only row in "known_drug.txt"
Note "known_drug.txt" has only one row while "bioresponse_descriptors_matrix.txt" has 299 rows.
Next compute the similarity vector S, by making a call to the appropriate ancestor class method

1e)(2)
Next use MK2, and its inherited method from Euclid to compute the distance vector D of Euclidean distances between every row in "bioresponse_descriptors_matrix.txt" vs the only row in "known_drug.txt", also compute the similarity vector S, by making a call to the appropriate ancestor class method, present in MK2

1f)
Write the similarity vectors computed and stored in MK1 and MK2 to files. Call the files result1.txt and result2.txt




2)
Using C++ STL library calls, sort the similarity vector S from largest to smallest, and print out the index for the top 10 most similar entries. We would apply this to the similarity vectors from MK1 and MK2, for comparison. The top 10 from MK1 and MK2 to sorted_result1.txt and sorted_result2.txt respectively.


Sample code from stack overflow provided to get sorted index rather than actual values after sorting array {15, 3, 0, 20}. You can use it to get started in creating a function that can do the task.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
std::vector<int> x = {15, 3, 0, 20};
std::vector<int> y(x.size());

std::size_t n(0);
std::generate(std::begin(y), std::end(y), [&]{ return n++; });

std::sort( std::begin(y), std::end(y), [&] (int i1, int i2) { return x[i1] < x[i2]; } );

for (int i =0; i<y.size() ; i++ )
std::cout << y[i] << ' ';
cout <<endl;
return 0;
}


./a.out

2 1 0 3


3) It is possible to use parallel algorithms for the objects in the problems described above. Write a separate and improved version of the program using appropriate parallel algorithms.



4) Bonus/Optional: 

a) it is possible to include an extra method in the ancestor class BaseCadd to sort out the similarities. Write an improved version of the base class BaseCadd, call it BaseCadd_V2 which includes this method for sorting the similarity values and returning the top 10. Please make it a separate code from 1 and 2. 

