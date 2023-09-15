using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
int solution(vector<int>& A) {
    int firstPosI = 0;
    sort(A.begin(), A.end());
    if (A[0] <= 0) {
        firstPosI = A.size() / 2;
        int temp = 0, temp2 = -1;
        while (firstPosI < A.size() && firstPosI != temp2) {
            if (A[firstPosI] <= 0) {
                temp2 = firstPosI;
                firstPosI += abs(firstPosI - temp) / 2 + abs(firstPosI - temp) % 2;
                temp = temp2;
            }
            else if (A[firstPosI - 1] <= A[firstPosI] && A[firstPosI - 1] > 0)
            {
                temp2 = firstPosI;
                firstPosI -= abs(firstPosI - temp) / 2 + abs(firstPosI - temp) % 2;
                temp = temp2;
            }
            else {
                break;
            }
        }
    }
    if (firstPosI >= A.size() || A[firstPosI] != 1) {
        return 1;
    }
    for (int i = firstPosI; i < A.size() - 1; i++) {
        if (A[i] < A[i+1]-1) {
            return A[i]+1;
        }
    }
    return A[A.size()-1] + 1;
}

//int main()
//{
//    vector <int> vec = { -1, 1, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
//    int output = solution(vec);
//}
