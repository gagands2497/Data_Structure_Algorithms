//to find Binomial coefficient
//n Choose k (k choosen from n)

#include <iostream>

using namespace std;

int nCk(int n, int k)
{
    int dp[n + 1][k + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (i == j || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << nCk(n, k) << endl;
}