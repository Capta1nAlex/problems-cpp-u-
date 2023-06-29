// MissingInteger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
int solution(vector<int>& A) {
    int firstPosI = 0;
    sort(A.begin(), A.end());
    if (A[0] <= 0) {
        firstPosI = A.size() / 2;
        int temp = 0, temp2 = -1;
        while (firstPosI < A.size() && firstPosI != temp2) {
            if (A[firstPosI] <= 0) {
                temp2 = firstPosI;
                firstPosI += abs(firstPosI - temp) / 2 + abs(firstPosI - temp) % 2;
                temp = temp2;
            }
            else if (A[firstPosI - 1] <= A[firstPosI] && A[firstPosI - 1] > 0)
            {
                temp2 = firstPosI;
                firstPosI -= abs(firstPosI - temp) / 2 + abs(firstPosI - temp) % 2;
                temp = temp2;
            }
            else {
                break;
            }
        }
    }
    if (firstPosI >= A.size() || A[firstPosI] != 1) {
        return 1;
    }
    for (int i = firstPosI; i < A.size() - 1; i++) {
        if (A[i] < A[i+1]-1) {
            return A[i]+1;
        }
    }
    return A[A.size()-1] + 1;
    // Implement your solution here
}

int main()
{
    vector <int> vec = { -1, 1, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
    int output = solution(vec);
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
