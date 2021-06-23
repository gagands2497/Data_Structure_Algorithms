#include <bits/stdc++.h>
using namespace std;

void IO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


int solve(vector<int> &values, vector<int> &weights, int W, int index)
{
    if ( index == values.size()) {
        return 0;
    }
    if (W == 0 ) {
        return 0;
    }
    if (weights[index] > W) {
        return solve(values, weights, W, index + 1);
    }

    int inc = values[index] + solve(values, weights, W - weights[index], index + 1);
    int exc = solve(values, weights, W, index + 1);

    return max(inc, exc);
}//we can do memorization to minimize the recursive calls

int knapsack(vector<int> &values, vector<int> &weights, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));


    //if n == 0 then the value generated will be 0 which we have take default

    //if W == 0 so therefore i can't pich anything and value  = 0 default


    //for any other values

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weights[i - 1] <= j) {
                //we can include that weight

                dp[i][j] = max(
                               values[i - 1] + dp[i - 1][j - weights[i - 1]],
                               dp[i - 1][j]
                           );
            } else {
                //not including that weight
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    IO();
    vector<int> values = {60, 100, 120};
    vector<int> weights = { 10, 20, 30 };
    int n = 3;
    int W = 50;
    int ans = solve(values, weights, W, 0);

    cout << ans << endl;
}