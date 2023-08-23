// Peaks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>& A) {
    vector<int> vecPeaks;
    int kMax = 0;
    for (int i = 1; i < A.size() - 1; i++) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            vecPeaks.push_back(i);
            i++;
        }
    }
    // probably correct (99% sure)
    if (vecPeaks.empty() == false) {
        int theLastPossible = 1;
        bool peaksExist = false;
        for (int i = 2; i < A.size() / 2; i++) {
            if (A.size() % i != 0) continue;
            int currentPeak = 0;
            for (int j = 0; j < A.size() / (A.size() / i); j++) {
                peaksExist = false;
                for (int k = j * A.size() / i; k < (A.size() / i) + j * A.size() / i && currentPeak < vecPeaks.size(); k++) {
                    if (k == vecPeaks[currentPeak]) {
                        peaksExist = true;
                        currentPeak++;
                    }
                }
                if (peaksExist == false) {
                    break;
                }
            }
            if (peaksExist == true) {
                theLastPossible = i;
            }
            if (peaksExist == false && i != 3) {
                break;
            }
        }
        cout << theLastPossible;
        return theLastPossible;
    }
    return 0;
}

int main()
{
    vector <int> vec = {1, 1, 7, 1, 1, 7, 1, 1, 7, 1, 1, 7, 1, 1, 7, 1, 1, 7, 1, 7, 1};
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
