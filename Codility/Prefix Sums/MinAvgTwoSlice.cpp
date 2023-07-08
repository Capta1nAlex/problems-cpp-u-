// MinAvgTwoSlice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int solution(vector<int>& A) {
    double min = INT_MAX;
    int minIndex = 0;
    double currentThing = 0;
    for (int i = 0; i < A.size()-1; i++) {
        currentThing = (A[i] + A[i+1])/2;
        if (currentThing < min) {
            min = currentThing;
            minIndex = i;
        }
    }
    for (int i = 0; i < A.size() - 2; i++) {
        currentThing = (A[i] + A[i + 1] + A[i + 2]) / 3;
        if (currentThing < min) {
            min = currentThing;
            minIndex = i;
        }
    }
    return minIndex;
}

int main()
{
    vector <int> i = { 4, 2, 2, 5, 1, 5, 8 };
    cout << solution(i);
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
