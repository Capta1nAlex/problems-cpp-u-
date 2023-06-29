#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int X, vector<int>& A) {
    vector<bool> newVec(X+1, false);
    int count = 0;
    for (int i = 0; i < A.size(); i++) {
        if (newVec[A[i]] == false) {
            count++;
            newVec[A[i]] = true;
        }
        if (count == X) {
            return i;
        }
    }
    return -1;
}

//int main()
//{
//    vector<int> a = {1, 3, 1, 4, 2, 3, 5, 4};
//    solution(5, a);
//}
