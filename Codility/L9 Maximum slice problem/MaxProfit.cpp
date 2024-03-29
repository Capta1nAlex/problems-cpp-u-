// MaxProfit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


int solution(vector<int>& A) {
    if (A.size() < 2) return 0;
    vector <int> deltaA;
    deltaA.push_back(0);
    for (int i = 1; i < A.size(); i++) {
        deltaA.push_back(A[i] - A[i - 1]);
    }

    int absoluteMax = deltaA[0];
    int localMax = deltaA[0];

    for (int i = 1; i < deltaA.size(); i++) {
        localMax = max(deltaA[i], localMax + deltaA[i]);
        absoluteMax = max(absoluteMax, localMax);
    }
    if (absoluteMax > 0) return absoluteMax;

    return 0;
}

int main()
{
    vector <int> vec = {23171, 21011, 21123, 21366, 21013, 21367};
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
