//------------Copyright Gagandeep Singh---------------------------


//-----------------Import Headers and define namespaces------------
#include <bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------


//------------------Function for Input Output----------------------
void IO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
//----------------------------------------------------------------


//-----------------Write Macros and Global here -------------------
#define ll long long
long long MOD = 1e9 + 7;
//-----------------------------------------------------------------

//---------------Write Functions and classes here------------------

ll solve(ll input[],ll n)
{
    ll ans = INT_MIN;
    for(int i = 0;i<n;i++)
    {
        ll curr_xor = 0;
        for(int j = i;j<n;j++)
        {
            curr_xor ^=  input[j];
            ans = max(ans,curr_xor);
        }
    }
    return ans;
}

//-----------------------------------------------------------------


//--------------------Main functions-------------------------------
int main()
{
    IO();
    ll n;
    cin>>n;
    ll input[n];

    for(int i = 0;i<n;i++)
    {
        cin>>input[i];
    }
    cout<<solve(input,n)<<endl;

}

//------------------Do calculatios here----------------------------