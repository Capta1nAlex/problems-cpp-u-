#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(string& S, vector<int>& P, vector<int>& Q) {
    vector <int> minImp;
    vector <int> currCounterA, currCounterC, currCounterG;
    int currentMin, currentG = 0, currentC = 0, currentA = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'G') {
            currentG++;
        }
        else if (S[i] == 'C') {
            currentC++;
        }
        else if (S[i] == 'A') {
            currentA++;
        }
        currCounterG.push_back(currentG);
        currCounterC.push_back(currentC);
        currCounterA.push_back(currentA);
    }
    for (int i = 0; i < P.size(); i++) {
        int from = P[i], to = Q[i];
        if (currCounterA[to] > currCounterA[from] || S[from] == 'A') {
            currentMin = 1;
        }
        else if (currCounterC[to] > currCounterC[from] || S[from] == 'C') {
            currentMin = 2;
        }
        else if (currCounterG[to] > currCounterG[from] || S[from] == 'G') {
            currentMin = 3;
        }
        else currentMin = 4;
        minImp.push_back(currentMin);
    }
    return minImp;
}

int main()
{
    vector <int> vec1 = {2, 5, 0};
    vector <int> vec2 = {4, 5, 6};
    string str = "CAGCCTA";
    solution(str, vec1, vec2);
    vector <int> vec3 = { 0, 0, 1 };
    vector <int> vec4 = { 0, 1, 1 };
    string str2 = "GT";
    solution(str2, vec3, vec4);
}