// FibFrog.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& A) {
    vector <int> fibonacci = { 1 };
    vector <int> avNumbers;
    int count = 2;
    int N = A.size() + 1;
    for (int i = 1; i < A.size() + 2; i++) {
        fibonacci.push_back(count);
        count += fibonacci[i - 1];
    }
    if (A.empty() == true) {
        return -1;
    }
    vector <int> jumps(N);
    for (int i = -1; i < N; i++) {
        if (i == -1 || jumps[i] > 0) {
            for (int j = 0; (i + fibonacci[j]) < N; j++) {
                int jumpToIndex = i + fibonacci[j];
                if (jumpToIndex == int(A.size()) || A[jumpToIndex] == 1) {
                    if (i == -1) jumps[jumpToIndex] = 1;
                    else if (jumps[jumpToIndex] <= 0) jumps[jumpToIndex] = jumps[i] + 1;
                    else jumps[jumpToIndex] = min(jumps[jumpToIndex], jumps[i] + 1);
                }
            }
        }
    }
    if (jumps[A.size()] <= 0)
        return -1;
    return jumps[A.size()];
}

int main()
{
    vector <int> vec = {1};
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
