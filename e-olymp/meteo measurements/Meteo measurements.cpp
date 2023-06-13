#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
	int n, k;
	double min, max;
	cin >> n >> k;
	vector <int> vec;
	double temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}
	temp = 0;
	for (int i = 0; i < k; i++) {
		temp += vec[i];
	}
	min = temp/k;
	max = temp/k;

	for (int i = 1; i <= n-k; i++)
	{
		temp += vec[i + k-1];
		temp -= vec[i - 1];
		if (temp/k > max) {
			max = temp/k;
		}
		else if (temp/k < min) {
			min = temp/k;
		}
	}
	cout << round(min) << endl << round(max);
}