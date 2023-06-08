// codility2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int>& A, int K) {
    int temp;
    for (int i = 0; i < K; i++) {
        for (int j = A.size() - 1; j > 0; j--) {
            temp = A[j];
            A[j] = A[j-1];
            A[j-1] = temp;
        }
    }
    return A;
}


int main()
{
    vector<int>a = { 3, 8, 9, 7, 6 };
    int k = 3;
    solution(a, k);
}