// Subprojects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, time, projects, temp;
	vector <int> vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int money = 0;
		cin >> time >> projects;
		for (int j = 0; j < projects; j++) {
			cin >> temp;
			vec.push_back(temp);
		}
		sort(vec.begin(), vec.end());
		for (int j = projects; j > projects - time && j > 0; j--) {
			money+=vec[j-1];
		}
		cout << money << endl;
		vec.clear();
	}
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
