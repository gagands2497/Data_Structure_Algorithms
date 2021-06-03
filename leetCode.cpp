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

void printVector(vector<int> nums,int number)
{
    cout<<"Vector number is "<<number<<endl;
    for(int i : nums)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
class Solution {
public:

    bool isValid(int i,int j,int n,int m)
    {
        if(i>=0 && i<n && j>=0 && j<m)return true;
        return false;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        if(n == 0)
        {
            return 0;
        }
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j])
                {
                    queue<pair<int,int>> waiting;

                    waiting.push(make_pair(i,j));
                    int islandArea = 0;
                    while(waiting.empty() == false)
                    {
                        pair<int,int> curr = waiting.front();
                        waiting.pop();
                        islandArea++;
                        visited[curr.first][curr.second] = true;
                        
                        //four directions
                        int dx[4] = {0,0,+1,-1};
                        int dy[4] = {+1,-1,0,0};   

                        for(int k = 0;k<4;k++)
                        {
                            int x = curr.first + dx[k];
                            int y = curr.second + dy[k];
                            if(isValid(x,y,n,m) && grid[x][y] && !visited[x][y])
                            {
                                waiting.push(make_pair(x,y));
                            }
                        }
                    }
                    ans = max(islandArea,ans);
                }
            }
        }
        return ans;
    }
};


//-----------------------------------------------------------------


//--------------------Main functions-------------------------------
int main()
{
    IO();
    Solution sol;
    vector<vector<int>> grid;
    grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};

    cout<<sol.maxAreaOfIsland(grid)<<endl;

}

//------------------Do calculatios here----------------------------