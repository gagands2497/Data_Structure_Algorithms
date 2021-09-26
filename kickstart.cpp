#include <bits/stdc++.h>
using namespace std;

void IO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool check(int *arr, int d, int n, int k)
{

    int count = 0;

    for (int i = 1; i < n; i++)
    {
        int a = arr[i];
        int end = arr[i + 1];

        count += ((end - a)%d != 0)?((end - a)/d):((end - a) / d)-1;
    }
    // cout << count << endl;
    if(count <=k){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    IO();
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        int n, k;
        cin >> n >> k;
        int arr[n + 1];
        arr[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        int diff = 0;

        for (int i = 1; i < n; i++)
        {
            diff = max(diff, arr[i + 1] - arr[i]);
        }

        int start = 0, end = diff;

        int ans = (start + end) / 2;

        while (start <= end)
        {
            ans = (start + end) / 2;
            bool flag = check(arr, ans, n, k);
            
            if(flag){
                if(ans == 1){
                    break;
                }
                end = ans - 1;
            }else{
                start = ans + 1;
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
}
