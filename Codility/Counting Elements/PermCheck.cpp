#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int solution(vector<int>& A) {
    sort(A.begin(), A.end());
    if (A[0] != 1) {
        return 0;
    }
    for (int i = 0; i < A.size()-1; i++) {
        if (A[i] != A[i + 1] - 1)
            return 0;
    }
    return 1;
}

//int main()
//{
//    vector<int> a = {2, 3};
//    int hz = solution(a);
//}
