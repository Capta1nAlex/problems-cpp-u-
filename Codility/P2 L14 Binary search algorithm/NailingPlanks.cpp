// NailingPlanks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

bool nailed(vector<int>& A, vector<int>& B, vector<int>& C, int maxNails) {
    int n = A.size();
    int m = C.size();
    vector<int> nailsCounter(m * 2 + 1, 0);
    for (int i = 0; i < maxNails; ++i) {
        nailsCounter[C[i]] = 1;
    }
    int counter = 0;
    for (int i = 0; i < nailsCounter.size(); i++) {
        counter += nailsCounter[i];
        nailsCounter[i] = counter;
    }
    for (int i = 0; i < n; ++i) {
        if (nailsCounter[A[i] - 1] == nailsCounter[B[i]]) return false;
    }
    return true;
}

int solution(vector<int>& A, vector<int>& B, vector<int>& C) {
    int lowerBound = 1, upperBound = C.size();
    if (!nailed(A, B, C, upperBound)) return -1;
    while (lowerBound < upperBound) {
        int nails = (lowerBound + upperBound) / 2;
        if (nailed(A, B, C, nails)) upperBound = nails;
        else lowerBound = nails + 1;
    }
    return lowerBound;
}

int main()
{
    vector <int> vec1 = { 1, 4, 5, 8 };
    vector <int> vec2 = { 4, 5, 9, 10 };
    vector <int> vec3 = { 4, 6, 7, 10, 2 };
    cout << solution(vec1, vec2, vec3);
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
