#include<bits/stdc++.h>
using namespace std;

void IO()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}
// Copy from here
void PrimeFactors(int N)
{
  for(int i = 2;i*i <=N ;i++)
  {
    if(N%i == 0)
    {
      int count = 0;
      while(N%i == 0)
      {
        count ++;
        N/=i;
      }
      cout<<"("<<i<<"^"<<count<<")";
    }
  }
  if(N>1)// means N is Prime
  {
    cout<<"("<<N<<"^"<<1<<")";
  }
}
//Upto here

signed main()
{
  IO();
  int n;
  cin>>n;
  PrimeFactors(n);
}
