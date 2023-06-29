// MaxCounters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
            if (myVec[A[i] - 1] <= counter) {
                myVec[A[i] - 1] = counter + 1;
            }
            if (myVec[A[i] - 1] > maxValue) {
                maxValue = myVec[A[i] - 1];
            }
        }
        else {
            counter = maxValue;
            //        for (int j = 0; j < N; j++) {
            //            myVec[j] = maxValue;
            //        }
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

/*vector<int> solution(int N, vector<int>& A) {
    vector<int> myVec(N, 0);
    int maxValue = 0;
    int counter = 0;
    bool unchanged = false;

    if (pow(N, 2) >= A.size()) {
        for (unsigned int i = 0; i < A.size(); i++) {
            if (A[i] <= N) {
                unchanged = true;
                int chupacabra = ++myVec[A[i] - 1];
                if (chupacabra > maxValue) {
                    maxValue = chupacabra;
                }
            }
            else if (unchanged == true) {
                unchanged = false;
                for (int j = 0; j < N; j++) {
                    myVec[j] = maxValue;
                }
            }
        }
    }
    else 
        for (unsigned int i = 0; i < A.size(); i++) {
        if (A[i] <= N) {
            unchanged = true;
            int chupacabra = ++myVec[A[i] - 1];
        }
        else if (unchanged == true) {
            unchanged = false;

            for (unsigned int i = 0; i < myVec.size(); i++) {
                if (maxValue > myVec[i]) {
                    maxValue = myVec[i];
                }
            }
            for (unsigned int j = 0; j < N; j++) {
                myVec[j] = maxValue;
            }
        }
    }
    return myVec;
}*/

/*vector<int> solution(int N, vector<int>& A) {
    int temp = 0, maxIndex = 0, maxV = 0;
    vector<int> myVec(N);
    if (pow(N, 2) >= A.size()) {
        for (int i = 0; i < A.size(); i++) {
            int index = A[i] - 1;
            if (A[i] <= N) {
                myVec[index]++;
                if (myVec[index] > temp) {
                    temp = myVec[index];
                }
            }
            else {
                maxV = temp;
                maxIndex = i;
            }
        }
        myVec.assign(N, maxV);
        for (int i = maxIndex; i < A.size(); i++) {
            int index = A[i] - 1;
            if (A[i] <= N) {
                myVec[index]++;
            }
        }
    }
    return myVec;
}
*/
int main()
{
    vector <int> mV = { 1, 1, 1, 1 };
    mV = solution(5, mV);
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
