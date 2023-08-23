// Ladder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int>& A, vector<int>& B) {
    size_t maxA = *std::max_element(A.begin(), A.end());
    size_t maxB = *std::max_element(B.begin(), B.end());
    vector<int> result(A.size(), 0);
    vector<size_t> fib(maxA + 2, 0);
    fib[1] = 1;

    for (size_t i = 2; i < maxA + 2; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]);

    for (size_t i = 0; i < A.size(); i++) {
        size_t mask = (1 << B[i]) - 1; // using bitwise 
        result[i] = fib[A[i] + 1] & mask;
        cout << result[i];
    }

    return result;
}
int main()
{
    vector <int> vec1 = {4, 4, 5, 5, 1};
    vector <int> vec2 = {3, 2, 4, 3, 1};
    solution(vec1, vec2);
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
