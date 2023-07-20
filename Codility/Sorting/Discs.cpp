typedef long long ll;
#include <algorithm>
#include <climits>
int solution(vector<int>& A) {
    vector<long long> start;
    vector<long long> end;
    int sum = 0;
    for (long i = 0; i < A.size(); i++) {
        start.push_back(i - ll(A[i]));
        end.push_back(i + ll(A[i]));
    }
    sort(start.begin(), start.end());
    start.push_back(LONG_MAX);
    sort(end.begin(), end.end());
    int dCurrent = 0, iStart = 0, iEnd = 0;
    while (iEnd < end.size()) {
        if (start[iStart] <= end[iEnd]) {
            sum += dCurrent;
            dCurrent++;
            iStart++;
        }
        else {
            dCurrent--;
            iEnd++;
        }
    }
    if (sum > 10000000) {
        return -1;
    }
    else return sum;
}
