// PassingCars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& A) {
	long long amountof1 = 0, result = 0;
	for (int i = A.size()-1; i >= 0; i--) {
		if (A[i] == 1) {
			amountof1++;
		}
		else
		{
			result += amountof1;
		}
	}
	if (result <= 1000000000)
		return result;
	else return -1;
}

int main()
{
	vector<int> vec = {0, 1};
	cout << solution(vec);
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
