#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int>& A) {
	if (A.size() == 0) {
		return 1;
	}
	sort(A.begin(), A.end());
	if (A[0] != 1) {
		return 1;
	}
	for (int i = 1; i < A.size(); i++) {
		if (A[i] != A[i - 1] + 1) {
			return A[i-1]+1;
		}
	}
	return A[A.size() - 1] + 1;
}

//int main()
//{
//	vector <int> a = {2, 1, 5, 3};
//	int temp = solution(a);
//}