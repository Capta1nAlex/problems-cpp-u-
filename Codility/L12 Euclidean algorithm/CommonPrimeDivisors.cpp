// CommonPrimeDivisors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

bool hasSamePrimeDivisors(int a, int b) {
	int gcdValue = gcd(a, b);
	int gcdA;
	int gcdB;
	while (a != 1) {
		gcdA = gcd(a, gcdValue);
		if (gcdA == 1)
			break;
		a = a / gcdA;
	}
	if (a != 1) {
		return false;
	}
	while (b != 1) {
		gcdB = gcd(b, gcdValue);
		if (gcdB == 1)
			break;
		b = b / gcdB;
	}
	if (b == 1) return true;
	return false;
}

int solution(vector<int>& A, vector<int>& B) {
	int samePairs = 0;
	for (int i = 0; i < A.size(); i++) {
		if (hasSamePrimeDivisors(A[i], B[i])) {
			samePairs++;
		}
	}
	return samePairs;
}

int main()
{
	vector <int> vec1 = { 2, 1, 2 };
	vector <int> vec2 = { 1, 2, 2 };
	cout << solution(vec1, vec2) << endl;
	vector <int> vec3 = { 15, 10, 9 };
	vector <int> vec4 = { 75, 30, 5 };
	cout << solution(vec3, vec4) << endl;
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
