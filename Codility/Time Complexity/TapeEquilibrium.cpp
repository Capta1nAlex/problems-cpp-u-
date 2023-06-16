// TapeEquilibrium.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int solution(vector<int>& A) {
    int sum = 0, newSum = 0, min = INT_MAX;
    for (int i = 0; i < A.size(); i++) {
        sum += A[i];
    }
    
    for (int i = 0; i < A.size()-1; i++) {
        sum -= A[i];
        newSum += A[i];
        if (abs(newSum - sum) < min) {
            min = abs(newSum - sum);
        }
    }
    return min;
}

//int main()
//{
//    vector <int> a = {3, 1, 2, 4, 3};
//    solution(a);
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
