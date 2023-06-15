// codility1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int N;
	int maxSum = 0, tempSum = 0;
	int binaryNum[32];
	cin >> N;
	int count = 0;
	while (N > 0) { //creating an array that will represent a binary number
		binaryNum[count] = N % 2; 
		N /= 2;
		count++;
	}
	for (int i = count; i > 0; i--) {  
		if (binaryNum[i] == 0) { // if there's a 0 in between of ones increase by 1 
			tempSum++;
		}
		else { 
			if (tempSum > maxSum) {
				maxSum = tempSum;
			}
			tempSum = 0; // reset zeros count
		}
	}
	cout << maxSum;
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