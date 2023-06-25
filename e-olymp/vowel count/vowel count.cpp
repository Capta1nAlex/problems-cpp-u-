#include <iostream>
using namespace std;
int main()
{
	string temp;
	int count = 0;
	cin >> temp;
	while (cin) {
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == 'A' || temp[i] == 'E' || temp[i] == 'I' || temp[i] == 'O' || temp[i] == 'U' || temp[i] == 'Y') {
				count++;
			}
		}
		cin >> temp;
	}
	cout << count;
}