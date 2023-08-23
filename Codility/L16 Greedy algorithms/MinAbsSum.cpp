#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>& A) {
    int minAbs = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] < 0) {
            A[i] = abs(A[i]);
        }
    }
    if (A.size() % 2 == 0 || A.size() == 1 || A.size() == 3) {
        sort(A.begin(), A.end());
        for (int i = A.size() - 1; i >= 0; i--) {
            if (minAbs <= 0) {
                minAbs += A[i];
            }
            else minAbs -= A[i];
        }
        return abs(minAbs);
    }
    else {
        int curSum1 = 0;
        int curSum2 = 0;
        vector <int> adding, substracting;
        for (int i = 0; i < A.size(); i++) {
            curSum1 += A[i];
            adding.push_back(A[i]);
        }
        for (int i = adding.size() - 1; i >= 0; i--) {
            int newPot = abs((curSum1 - adding[i]) - (curSum2 + adding[i]));
            if (newPot <= abs(curSum1 - curSum2) && curSum1 - adding[i] >= curSum2 + adding[i]) {
                curSum2 += adding[i];
                substracting.push_back(adding[i]);
                curSum1 -= adding[i];
                adding.erase(adding.begin() + i);
            }
        }
        for (int i = substracting.size() - 1; i >= 0; i--) {
            int newPot = abs((curSum1 + substracting[i]) - (curSum2 - substracting[i]));
            if (newPot <= abs(curSum2 - curSum1)) {
                curSum1 += substracting[i];
                adding.push_back(substracting[i]);
                curSum2 -= substracting[i];
                substracting.erase(substracting.begin() + i);
            }
        }
        for (int i = adding.size() - 1; i > 0; i--) {
            int newPot = abs((curSum1 - adding[i]) - (curSum2 + adding[i]));
            if (newPot <= abs(curSum1 - curSum2)) {
                curSum2 += adding[i];
                substracting.push_back(adding[i]);
                curSum1 -= adding[i];
                adding.erase(adding.begin() + i);
            }
        }
        minAbs = curSum1 - curSum2;
        return abs(minAbs);
    }
}

int main() {
    // Tests I used in order to understand whether program is working correctly
    vector <int> i1 = {}; // 0
    vector <int> i2 = { 10, 11, 12, 13, 14 }; // 6
    vector <int> i3 = { 5, 4, 3, 3, 3, 3, 3 }; // 0
    vector <int> i4 = { 10, 1, 1, 1, 1, 1, 1 }; // 4
    vector <int> i5 = { 42, 42, 42, 42, 5, 42, 5, 42, -5, 5, -5, 42, 42, 5, 5, 5, 5, 5, 5, 5, 5, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 }; // 5
    vector <int> i6 = { 2, 4, 6, 11, 20 }; // 1
    vector <int> i7 = { 8, 6, 4, 2 }; // 0
    cout << solution(i1) << endl;
    cout << solution(i2) << endl;
    cout << solution(i3) << endl;
    cout << solution(i4) << endl;
    cout << solution(i5) << endl;
    cout << solution(i6) << endl;
    cout << solution(i7) << endl;

    return 0;
}

// I hate my life. But it could be worse, I guess.
