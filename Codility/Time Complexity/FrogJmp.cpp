#include <iostream>
using namespace std;
int solution(int X, int Y, int D) {
    if ((Y - X) % D == 0)
    return (Y - X) / D;
    else return (Y - X) / D + 1;
    // Implement your solution here
}

//int main()
//{
//    int x, y, d;
//    cin >> x >> y >> d;
//    solution(x, y, d);
//}
