#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
	int n, k; // n and k - the number of temperature measurements and the number of days to calculate the average temperature
	double min, max; 
	cin >> n >> k;
	vector <int> vec;
	double input, avg = 0;
	for (int i = 0; i < n; i++) {
		cin >> input;
		vec.push_back(input);
	}
	for (int i = 0; i < k; i++) { 
		avg += vec[i];
	}
	min = avg/k; // setting min as an average from first k days
	max = avg/k; // setting max as an average from first k days

	for (int i = 1; i <= n-k; i++)
	{
		avg += vec[i + k-1]; // adding next day to the calculation 
		avg -= vec[i - 1]; // removing previous day from the calculation
		if (avg/k > max) { 
			max = avg/k;
		}
		else if (avg/k < min) {
			min = avg/k;
		}
	}
	cout << round(min) << endl << round(max);
}
