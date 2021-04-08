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
void PrimeFactors(int n)
{
  for(int i = 2;i<=n;i++)
  {
    if(n == 0 || n == 1)break;
    if(n%i == 0)
    {
      int count = 0;
      while(n%i == 0)
      {
        count++;
        n /= i;
      }
      if(n==0 || n==1)
      {
        cout<<"("<<i<<"^"<<count<<")";
      }
      else
      {
        cout<<"("<<i<<"^"<<count<<")*";
      }
    }
  }
  cout<<endl;
}
//to here
signed main()
{
  IO();
  int n;
  cin>>n;
  PrimeFactors(n);
}
