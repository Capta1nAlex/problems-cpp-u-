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

//int main()
//{
//	vector<int> vec = {0, 1};
//	cout << solution(vec);
//}
