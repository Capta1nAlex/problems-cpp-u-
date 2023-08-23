// CountSemiprimes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<int> solution(int N, vector<int>& P, vector<int>& Q) {
    vector<bool> sieve(N, true);
    vector <int> result;
    if (N <= 1) {
        result.push_back(0);
        return result;
    }
    set<int> primes;
    set<int> semiPrimes;
    vector<int> numIndex(N+1, 0);
    sieve[0] = false;
    sieve[1] = false;
    sieve[2] = true;
    for (int i = 2; i < sieve.size(); i++) {
        if (sieve[i] == true) {
            for (int j = i; j < double(sieve.size()) / i; j++)
                sieve[i * j] = false;
        }
    }
    for (int i = 0; i < sieve.size(); i++) {
        if (sieve[i] == true) {
            primes.insert(i);
        }
    }
    for (auto i = primes.begin(); *i**i <= N; i++) {
        for (auto j = i; *j**i <= N; j++) {
            semiPrimes.insert(*i**j);
        }
    }
    int count = 0;
    auto it = semiPrimes.begin();
    for (int i = 0; i <= N; i++) {
        if (it != semiPrimes.end() && *it == i) {
            it++;
            count++;
        }
        numIndex[i] = count;
    }
    for (int i = 0; i < Q.size(); i++) {
        result.push_back(numIndex[Q[i]]-numIndex[P[i]-1]);
    }
    return result;
}

int main()
{
    int N = 50000;
    vector <int> vec1 = { 1, 1, 1, 1, 1, 1};
    vector <int> vec2 = { 50000, 50000, 50000, 50000, 50000, 50000, };
    solution(N, vec1, vec2);
    int N2 = 26;
    vector <int> vec3 = { 1, 4, 16};
    vector <int> vec4 = { 26, 10, 20};
    solution(N2, vec3, vec4);
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
