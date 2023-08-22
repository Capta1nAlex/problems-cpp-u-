// Brackets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution(string& S) {
    bool oval = false, brace = false, sqr = false;
    string newS = " ";
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == ')' && (newS[newS.size() - 1] == '(')) {
            newS.erase(newS.size() - 1, 1);
        }
        else if (S[i] == ')') return 0;
        if (S[i] == '}' && (newS[newS.size() - 1] == '{')) {
            newS.erase(newS.size() - 1, 1);
        }
        else if (S[i] == '}') return 0;
        if (S[i] == ']' && (newS[newS.size() - 1] == '[')) {
            newS.erase(newS.size() - 1, 1);
        }
        else if (S[i] == ']') return 0;
        if (S[i] == '(') {
            newS.push_back('(');
        }
        if (S[i] == '{') {
            newS.push_back('{');
        }
        if (S[i] == '[') {
            newS.push_back('[');
        }
    }
    if (newS == " ") {
        return 1;
    }
    return 0;
}

int main()
{
    string str = "({{({}[]{})}}[]{})";
    solution(str);
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
