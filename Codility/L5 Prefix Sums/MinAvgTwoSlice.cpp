#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int solution(vector<int>& A) {
    double min = INT_MAX;
    int minIndex = 0;
    double currentThing = 0;
    for (int i = 0; i < A.size()-1; i++) {
        currentThing = (A[i] + A[i+1])/2;
        if (currentThing < min) {
            min = currentThing;
            minIndex = i;
        }
    }
    for (int i = 0; i < A.size() - 2; i++) {
        currentThing = (A[i] + A[i + 1] + A[i + 2]) / 3;
        if (currentThing < min) {
            min = currentThing;
            minIndex = i;
        }
    }
    return minIndex;
}

//int main()
//{
//    vector <int> i = { 4, 2, 2, 5, 1, 5, 8 };
//    cout << solution(i);
//}
