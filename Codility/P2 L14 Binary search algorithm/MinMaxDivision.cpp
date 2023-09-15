// MinMaxDivision.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

bool checkMedium(int mediumBound, vector<int>& Vec, int K) {
    int localK = 0, miniGroup = 0;
    for (int i = 0; i < Vec.size(); i++) {
        miniGroup += Vec[i];
        if (miniGroup > mediumBound) {
            localK++;
            miniGroup = 0;
            i--;
        }
        if (localK >= K) {
            return false;
        }
    }
    return true;
}

int solution(int K, int M, vector<int>& A) {
    int lowerBound = 0, upperBound = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] >= lowerBound) {
            lowerBound = A[i];
        }
        upperBound += A[i];
    }

    if (K >= A.size())
        return lowerBound;

    int mediumBound = (upperBound + lowerBound) / 2;
    while (lowerBound < upperBound) {
        mediumBound = (upperBound + lowerBound) / 2;
        if (checkMedium(mediumBound, A, K)) {
            upperBound = mediumBound;
        }
        else lowerBound = mediumBound + 1;
    }
    return lowerBound;
}

int main()
{
    vector <int> vec = {2, 1, 5, 1, 2, 2, 2};
    cout << solution(3, 100000, vec) << endl; // 6
    vector <int> vec2 = { 5, 2, 3, 4, 6 };
    cout << solution(3, 6, vec2) << endl; // 7 
    vector <int> vec3 = { 5, 3};
    cout << solution(1, 10, vec3) << endl; // 8
    vector <int> vec4 = { 4, 1, 2, 7 };
    cout << solution(2, 7, vec4) << endl; // 7
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
