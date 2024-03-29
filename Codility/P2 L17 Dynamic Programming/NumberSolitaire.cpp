// NumberSolitaire.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std; 

int solution(vector<int>& A) {
    vector<int> bestPicks;
    bestPicks.push_back(A[0]); // we always start from element 0
    for (int i = 1; i < A.size(); i++) {
        int maxPick = INT_MIN; 
        for (int die = 1; die <= 6; die++) {
            if (i - die >= 0) {
                maxPick = max(bestPicks[i - die] + A[i], maxPick);
            }
        }
        bestPicks.push_back(maxPick);   
    }

    return bestPicks[A.size() - 1];
}
int main()
{
    vector <int> vec = { -1, -1, -2, -2, -2, -2, -2, -2, -2, -1 };
    cout << solution(vec);
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
