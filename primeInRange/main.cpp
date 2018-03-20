#include <bits/stdc++.h>

using namespace std;
#define MAX 100001
typedef long long ll;

vector<int>* sieve()
{
    bool isPrime[MAX];
    for(int i=0;i<MAX;i++)
    {
        isPrime[i]=true;
    }
    for(int i=2;i*i<MAX;i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<MAX;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
    vector<int>* primes=new vector<int>();
    primes->push_back(2);
    for(int i=3;i<MAX;i+=2)
    {
        if(isPrime[i])
        {
            primes->push_back(i);
        }
    }
    return primes;
}

void printPrimes(ll l,ll r,vector<int>* &primes)
{
    bool isPrime[r-l+1];
    for(int i=0;i<=r-l;i++)
    {
        isPrime[i]=true;
    }
    for(int i=0;primes->at(i)*(ll)primes->at(i)<=r;i++)
    {
        int currPrime=primes->at(i);
        //Just smaller or equal value to l
        ll base=(l/currPrime)*currPrime;
        if(base<l)
        {
            base+=currPrime;
        }
        //Mark all multiples within l to r as false
        for(ll j=base;j<=r;j+=currPrime)
        {
            isPrime[j-l]=false;
        }
        //There maybe a case where base is itself a prime no.
        if(base==currPrime)
        {
            isPrime[base-l]=true;
        }
    }
    for(int i=0;i<=r-l;i++)
        {
            if(isPrime[i])
            {
                cout<<(i+l)<<endl;
            }
        }
}

int main()
{
    vector<int>* primes=sieve();
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        printPrimes(l,r,primes);
    }
    return 0;
}
