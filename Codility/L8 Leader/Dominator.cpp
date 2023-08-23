// Dominator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<int>& A) {
	vector<int> temp = A;
	sort(A.begin(), A.end());
	int count = 1, max = INT_MIN;
	long long dominator = INT_MIN - 1;
	for (int i = 1; i < A.size(); i++) {
		if (A[i] == A[i-1]) {
			count++;
		}
		else count = 1;
		if (count > A.size() / 2) {
			dominator = A[i];
			break;
		}
	}
	if (count < A.size() / 2)
		return -1;
	else for (int i = 0; i < A.size(); i++) {
		if (temp[i] == dominator) {
			cout << i;
			return i;
		}
	}
	return dominator;
}

int main()
{
	vector <int> vec = { 3,4,3,2,3,-1,3,3 };
	solution(vec);
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
