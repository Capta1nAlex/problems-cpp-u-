#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
    int m, temp = 0, reminder = 0; 
    cin >> m;
    vector <int> vec;
    while (m!=0) {
        for (int j = m; j > 0; j/=2) {
            temp++;
            reminder = j;
        }
        if (reminder % 2 != 0) { 
            temp--;
        }
        temp = pow(2, temp);
        vec.push_back(temp);
        m -= temp;
        temp = 0;
    }
    for (int i = vec.size() - 1; i >= 0; i--) {
        cout << vec[i] << " ";
    }
}