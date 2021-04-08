#include<bits/stdc++.h>
using namespace std;

void IO()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}
//copy from here
std::vector<int> primes;
bool isPrime[90000001];

void sieve()
{
  int maxN = 90000000;
  isPrime[0] = isPrime[1] = true;//using true for not prime

  for(int i = 2;i*i<=maxN;i++)
  {
    if(isPrime[i] == false)
    {
      for(int j = (i*i);j <= maxN;j+=i)
      {
        isPrime[j] = true;
      }
    }
  }
  for(int i = 2;i<=maxN;i++)
  {
    if(isPrime[i] == false)
    {
      primes.push_back(i);
    }
  }

}

//to here
signed main()
{
  IO();
  int t;
  cin>>t;
  sieve();
  while(t--)
  {
    int k;
    cin>>k;
    cout<<primes[k-1]<<endl;
  }
}
