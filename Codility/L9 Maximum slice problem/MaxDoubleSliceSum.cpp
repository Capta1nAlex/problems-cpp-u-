// MaxDoubleSliceSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& A) {
    int maxSum = 0;    
    int* slice1LocalMax = new int[A.size()];
    slice1LocalMax[0] = 0;
    int* slice2LocalMax = new int[A.size()];
    slice2LocalMax[A.size() - 1] = 0;
    for (int i = 1; i < A.size(); i++) {
        slice1LocalMax[i] = max(slice1LocalMax[i - 1] + A[i], 0);
    }
    for (int i = A.size() - 2; i >= 0; i--) {
        slice2LocalMax[i] = max(slice2LocalMax[i + 1] + A[i], 0);
    }    
    for (int i = 1; i < A.size() - 1; i++) {
        maxSum = max(maxSum, slice1LocalMax[i-1] + slice2LocalMax[i + 1]);
    }
    cout << maxSum;
    return maxSum;
}


int main()
{
    vector <int> vec = {3,2,6,-1,4,5,-1,2};
    solution(vec);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
