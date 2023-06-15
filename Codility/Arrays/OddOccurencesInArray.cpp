#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int>& A) {
	sort(A.begin(), A.end());
	for (int i = 0; i < A.size()-1; i+=2) {
		if (A[i] != A[i+1]) {
			cout << A[i];
			return A[i];
		}
	}
	cout << A[A.size() - 1];
	return A[A.size()-1];
}

int main()
{
	vector<int> A = {1, 1, 2, 2, 3, 3, 5, 5, 8, 8, 9, 9, 7};
	solution(A);
}