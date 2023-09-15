#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int solution(vector<int>& A) {
    int sum = 0, newSum = 0, min = INT_MAX;
    for (int i = 0; i < A.size(); i++) {
        sum += A[i];
    }
    
    for (int i = 0; i < A.size()-1; i++) {
        sum -= A[i];
        newSum += A[i];
        if (abs(newSum - sum) < min) {
            min = abs(newSum - sum);
        }
    }
    return min;
}

//int main()
//{
//    vector <int> a = {3, 1, 2, 4, 3};
//    solution(a);
//}
