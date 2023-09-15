#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<int> solution(int N, vector<int>& A) {
    vector<int> myVec(N, 0);
    int maxValue = 0;
    int counter = 0;
    int lastIncI = 0;

    for (unsigned int i = 0; i < A.size(); i++) {
        if (A[i] <= N) {
            ++myVec[A[i] - 1];
            if (myVec[A[i] - 1] <= counter) { // updating only those items that have not been updated since the max counter was triggered and were incremented later, decreasing O from N^2 to N+M
                myVec[A[i] - 1] = counter + 1;
            }
            if (myVec[A[i] - 1] > maxValue) {
                maxValue = myVec[A[i] - 1];
            }
        }
        else {
            counter = maxValue;
            lastIncI = i;
        }
    }
    if (counter != 0) {
        fill(myVec.begin(), myVec.end(), counter); 
        for (int i = lastIncI + 1; i < A.size(); i++) { 
            myVec[A[i] - 1]++;
        }
    }
    return myVec;
}

//int main()
//{
//    vector <int> mV = { 1, 1, 1, 1 };
//    mV = solution(5, mV);
//}
