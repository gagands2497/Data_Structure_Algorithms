#include <queue>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int M = 3e5 + 233;
const int Mod = 1e9 + 7;
const int INF = 0x3f3f3f;
typedef long long ll;
char s[M];
vector <int> v[M];
int vis[M], in[M];
int dp[M][40] ;//The number of subcharacters ending in i
 
int dfs(int x)
{
    in[x] = 1;
    vis[x] = 1;
    dp[x][s[x]-'a'] = 1;
    for(int i=0;i<v[x].size();i++)
    {
        int &t = v[x][i];
        if(in[t]) printf("-1\n"), exit(0);
        if(!vis[t]) dfs(t);
        for(int j=0;j<26;j++)
            dp[x][j] = max(dp[t][j]+((s[x]-'a')==j),dp[x][j]);
    }
    in[x] = 0;
}
int main()
{
    int n,m;
    string input;
    cin>>input;
    for(int i = 0;i<input.length();i++)
    {
        s[i] = input[i];
    }
    s[input.length()] = '\0';
    int x[m],y[m];
    for(int i = 0;i<m;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<m;i++)
    {
        v[x[i]].push_back(y[i]);
        if(x[i] == y[i]) return 0*puts("-1");
    }
    for(int i=1;i<=n;i++)  if(!vis[i])  dfs(i);
    int ans = 0;
    for(int i=1;i<=n;i++)
    for(int j=0;j<30;j++)
        ans  = max(ans,dp[i][j]);
    printf("%d\n",ans);
}
// 3 3  aaa 1 2 2 3 3 1