// CountNonDivisible.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int>& A) {
    bool allTheSame = true;
    vector<int> counts(*std::max_element(A.begin(), A.end()) + 1);
    for (int i = 0; i < A.size() - 1; i++)
    {
        counts[A[i]] += 1;
        if (A[i] != A[i + 1]) {
            allTheSame = false;
        }
    }
    counts[A[A.size() - 1]] += 1;
    std::vector<int> answer(A.size(), 0);
    if (allTheSame == false) {
        for (int i = 0; i < A.size(); i++) {
            int divisors = 0;
            for (int j = 1; j * j <= A[i]; j++)
            {
                if (A[i] % j == 0)
                {
                    divisors += counts[j];
                    if (A[i] / j != j)
                    {
                        divisors += counts[A[i] / j];
                    }
                }
            }
            answer[i] = A.size() - divisors;
        }
    }
    return answer;
}
/*int maxInt = *max_element(A.begin(), A.end());
vector<bool> sieve(maxInt + 1, true);
vector<int> trueCount;
sieve[0] = false;
sieve[1] = false;
sieve[2] = true;
int trueC = 0;
for (int i = 2; i < maxInt; i++) {
    if (sieve[i] == true) {
        for (int j = i; j < double(sieve.size()) / i; j++) {
            sieve[i * j] = false;
        }
        trueC++;
    }
    trueCount.push_back(trueC);
}
vector<int> result;
for (int i = 0; i < A.size(); i++) {
    result.push_back(trueCount[A[i]]);
}
return result;*/
int main()
{
    vector <int> vec = {3, 1, 2, 3, 6};
    solution(vec);
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
