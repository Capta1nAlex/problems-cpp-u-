// FrogRiverOne.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int X, vector<int>& A) {
    vector<bool> newVec(X+1, false);
    int count = 0;
    for (int i = 0; i < A.size(); i++) {
        if (newVec[A[i]] == false) {
            count++;
            newVec[A[i]] = true;
        }
        if (count == X) {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {1, 3, 1, 4, 2, 3, 5, 4};
    solution(5, a);
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
