// CountDistinctSlices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(int M, vector<int>& A) {
    vector <int> Addition, Substriction;
    vector <int> myVec;
    int temp = 0, beginning = 0, oldbeginning = 0;
    for (int i = 0; i < A.size(); i++) {
        myVec.push_back(A[i]);
        bool exists = find(myVec.begin(), myVec.end(), A[i]) != myVec.end() - 1;
        if (exists == true) {
            while (A[beginning] != A[i]) {
                beginning++;
            }
            vector<int>::iterator it1, it2;
            myVec.erase(myVec.begin(), myVec.begin() + beginning);
            Addition.push_back(temp);
            temp -= beginning - oldbeginning;
            Substriction.push_back(beginning - oldbeginning);
            oldbeginning = beginning;
        }
        else temp++;
    }
    return min(temp, 1000000000);
}
 
int main()
{
    vector<int> vec = { 2, 1, 2 };
    cout << solution(6, vec) << endl;
    vector<int> vec2 = { 3, 4, 5, 5, 2 };
    cout << solution(6, vec2) << endl;
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
