#include <iostream>
using namespace std;

int solution(int A, int B, int K) {
    int start = (B - B % K);
    int end = (A + (K - A % K));
    int result = (start - end) / K;
    if (A%K == 0)
        result++;
    result++;
    return result;
}

//int main()
//{
//   cout << solution(11, 345, 17);
//}
