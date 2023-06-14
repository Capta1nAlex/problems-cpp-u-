// Julius Caesar cipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int shift; // Amount of shifts per letter
    cin >> shift;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] - shift < 65) { // 65-90 values of char are used for saving [A...Z] letters
            s[i] = 90 - (64 - (s[i] - shift));
        }
        else s[i] -= shift;
    }
    cout << s;
}
