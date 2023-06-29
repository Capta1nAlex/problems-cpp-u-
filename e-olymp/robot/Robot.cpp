// Robot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int pos = 0, result = 1;
    vector <bool> truthtable(20000, false);
    truthtable[10000] = true;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') {
            pos += 1;
            if (truthtable[pos + 10000] == false) {
                truthtable[pos + 10000] = true;
                result++;
            }
        }
        else if (s[i] == 'L') {
            pos -= 1;
            if (truthtable[pos + 10000] == false) {
                truthtable[pos + 10000] = true;
                result++;
            }
        }
    }
    cout << result;
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
