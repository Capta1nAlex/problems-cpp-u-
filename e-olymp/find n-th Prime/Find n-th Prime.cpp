#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX_SIZE 7368787 // maximum prime is 7,368,787
void SieveOfEratosthenes(vector<int>& primes)
{
    bool IsPrime[MAX_SIZE];
    memset(IsPrime, true, sizeof(IsPrime));
    for (int p = 2; p * p < MAX_SIZE; p++) {
        if (IsPrime[p] == true)
            for (int i = p * p; i < MAX_SIZE; i += p)
                IsPrime[i] = false;
    }
    for (int p = 2; p < MAX_SIZE; p++)
        if (IsPrime[p])
            primes.push_back(p);
}

int main()
{
    vector<int> primes;
    SieveOfEratosthenes(primes);
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cout << primes[temp - 1] << endl;
    }
    return 0;
}