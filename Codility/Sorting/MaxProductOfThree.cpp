#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>& A) {
    sort(A.begin(), A.end());
    vector <int> newVec;
    int max = INT_MIN;
    if (A.size() >= 5) {
        newVec.push_back(A[0]);
        newVec.push_back(A[1]);
        newVec.push_back(A[2]);
        newVec.push_back(A[A.size() - 1]);
        newVec.push_back(A[A.size() - 2]);
        newVec.push_back(A[A.size() - 3]);
    }
    else for (int i = 0; i < A.size(); i++) {
            newVec.push_back(A[i]);
        }
    for (int i = 0; i < newVec.size() - 2; i++) {
        for (int j = i + 1; j < newVec.size() - 1; j++) {
            for (int k = j + 1; k < newVec.size(); k++) {
                if (max < newVec[i] * newVec[j] * newVec[k]) {
                    max = newVec[i] * newVec[j] * newVec[k];
                }
            }
        }
    }
    cout << max;
    return max;
    // Implement your solution here
}

int main()
{
    vector <int> vec = {4, 5, 1, 0};
    solution(vec);
}