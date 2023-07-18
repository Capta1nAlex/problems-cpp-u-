#include <iostream>
#include <vector>
using namespace std;

//100% correctness, 62% perfomance. Working on a fix right now.
int solution(vector<int>& A) {
    vector<long long> start;
    vector<long long> end;
    int sum = 0;
    for (long i = 0; i < A.size(); i++) {
        start.push_back(i - long long(A[i]));
        end.push_back(i + long long(A[i]));
    }
    for (int i = 0; i < A.size(); i++) {
        int iStart = start[i];
        int iEnd = end[i];
        for (int j = i + 1; j < A.size(); j++) {
            if ((iEnd >= start[j] && iStart <= end[j])) {
                sum++;
            }
        }
    }
    cout << sum;
    if (sum > 10000000) {
        return -1;
    }
    else return sum;
}

int main()
{
    vector <int> vec {0, 2147483647 };
    solution(vec);
}