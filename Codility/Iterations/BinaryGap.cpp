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
