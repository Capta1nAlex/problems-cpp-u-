// MaxNonoverlappingSegments.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
int solution(vector<int>& A, vector<int>& B) {
    if (A.size() <= 1) {
        return A.size();
    }
    int count = 1;
    int prev_num = B[0];
    for (int i = 1; i < A.size(); i++) {
        if (A[i] > prev_num) {
            count++;
            prev_num = B[i];
        }
    }
    cout << count;
    return count;
}
int main(){
    vector <int> vec1 = {1, 2, 3, 4, 5};
    vector <int> vec2 = {3, 4, 4, 5, 6};
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
