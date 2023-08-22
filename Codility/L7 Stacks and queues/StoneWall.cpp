// StoneWall.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int>& H) {
    int stones = 0;
    int stack_num = 0;

    for (int i = 0; i < H.size(); i++) {
        while (stack_num > 0 && H[stack_num - 1] > H[i])
            stack_num -= 1;
            if (stack_num > 0 && H[stack_num - 1] == H[i]) {
            }
            else {
                stones += 1;
                H[stack_num] = H[i];
                stack_num += 1;
            }
    }
    return stones;
}

int main()
{
    vector <int> vec = { 8, 8, 5, 7, 9, 8, 7, 4, 8 };
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
