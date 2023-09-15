// Flags.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>& A) {
    vector<int> vecPeaks;
    int kMax = 0;
    for (int i = 1; i < A.size()-1; i++) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) {
            vecPeaks.push_back(i);
            i++;
        }
    }
    if (vecPeaks.empty() != true) {
        for (int i = 1; i <= sqrt(A.size())+1; i++) {
            int count = 1;
            int temp = 0;
            for (int j = 1; count < i && j < vecPeaks.size(); j++) {
                if (vecPeaks[j] - vecPeaks[temp] >= i) {
                    count++;
                    temp = j;
                }
            }
            if (count > kMax)
                kMax = count;
        }
    }
    cout << kMax;
    return kMax;
}

int main()
{
    vector <int> vec = { 3, 4, 2};
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
