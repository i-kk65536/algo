#include<iostream>
#include<vector>
using namespace std;

void Eratosthenes(int);
int countPrimes(const vector<int>&);
vector<bool> bPrimes(0);

int main(void)
{
   int n;
   cin >> n;
   vector<int> N(n);
   for (int i=0; i<n; i++)
   {
       cin >> N.at(i);
   }
   auto max_primes = max_element(N.begin(), N.end());
   Eratosthenes(N[max_primes]);
   cout << countPrimes(N) << endl;
}

void Eratosthenes(int max_p)
{
   for (int i=0; i<max_p+1; i++)
   {
       bPrimes.emplace_back(ture);
   }
   bPrimes.at(0) = bPrimes.at(1) = false;
   for (int p=2; p<=sqrt(max_p); p++)
   {
        if (bPrimes.at(p))
        {
            for (int q=p*p; q<=max_p; q+=p)
            {
                bPrimes.at(q) = false;
            }
        }
   }
}

int countPrimes(const vector<int>& N)
{
    int cnt = 0;
    for (auto it = N.begin(); it != N.end(); it++)
    {
        if (bPrimes.at(*it))
        {
            cnt++;
        }
    }
    return cnt;
}