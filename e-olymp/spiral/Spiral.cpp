#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    int N, I, J;
    cin >> N >> I >> J;
    int row;

    int x, y;
    if (N - I > I - 1) {
        x = I - 1;
    } else x = N - I;
    if (N - J > J - 1) {
        y = J - 1;
    } else y = N - J;

    if (x > y) {
        row = y;
    } else row = x;
    //routine for finding "row"

    int result = N * N - pow((N / 2 + N % 2 - row) * 2 - N % 2, 2);
    result++;    
    //finding the minimal number in the row
    
    int tempI = row + 1, tempJ = row + 1;
    while (tempI != I || tempJ != J) { // iteratting through row in spiral
        if (tempJ < N - row && tempI == row + 1) {
            tempJ++;
        }
        else if (tempI < N - row && tempJ == N - row) {
            tempI++;
        }
        else if (tempJ > row + 1) {
            tempJ--;
        }
        else {
            tempI--;
        }
        result++;
    }
    cout << result;
}