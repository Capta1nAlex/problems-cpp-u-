// EquiLeader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int findLeader(vector<int>& A) {
	vector<int> temp = A;
	sort(temp.begin(), temp.end());
	int count = 1, max = INT_MIN;
	long long dominator = -1000000001;
	for (int i = 1; i < temp.size(); i++) {
		if (temp[i] == temp[i - 1]) {
			count++;
		}
		else count = 1;
		if (count > temp.size() / 2) {
			dominator = temp[i];
			cout << "dominator:" << dominator;
			return dominator;
		}
	}
	if (count < temp.size() / 2)
		return -1000000001;
	return dominator;
}

int countLeader(vector<int>& A, int leader) {
	int count = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == leader) {
			count += 1;
		}
	}
	cout << "count:" << count;
	return count;
}

int solution(vector<int>& A) {
	int leader = findLeader(A);
	if (leader > 1000000000 || leader < -1000000000) return 0;
	int total_occurences = countLeader(A, leader);
	int result = 0;
	int cur_occurences = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == leader) {
			cur_occurences += 1;
		}
		if ((total_occurences - cur_occurences) > (A.size() - i - 1) / 2 && cur_occurences > (i + 1) / 2){
			result++;
		}
	}
	return result;
}

int main()
{
	vector <int> vec = { 4, 3, 4, 4, 4, 2 };
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
