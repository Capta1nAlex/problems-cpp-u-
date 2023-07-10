#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;  
int main() {
	int n, temp;
	vector <int> vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}
	vector <int> vec1 = vec;
	sort(vec.begin(), vec.end());
	int count = 0;
	for (int i = vec.size() - 1; i >= 0; i--) {
		for (int j = 0; j < vec1.size(); j++) {
			if (vec[i] == vec1[j]) {
				cout << j+1 << " ";
				vec1[j] = -1;
			}
		}
	}
}
