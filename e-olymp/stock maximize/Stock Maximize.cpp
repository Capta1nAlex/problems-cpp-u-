// Stock Maximize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, input;
	vector <int> vec;
	int maxI = 0, max = 0, recall = 0, recallI = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		vec.push_back(input);
		if (vec[i] > max) {
			max = vec[i];
			maxI = i;
		}
	}
	int reduction = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (max <= vec[j]) {
				max = vec[j];
				if (recall == max) {
					break;
				}
				maxI = j;
				i = maxI;
			}
		}
		for (int k = recallI+1; k < maxI; k++) {
			reduction += vec[k];
		}
		sum += ((maxI - recallI - 1) * max - reduction);
		max = 0;
		reduction = 0;
		recall = max;
		recallI = maxI;
	}
	cout << sum;
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
