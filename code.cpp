#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long MOD = 1e9 + 7;
void IO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    IO();
    int t;
    cin >> t;
    while (t--) {
        int n, w, r;
        cin >> n >> w >> r;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int start = 0;
        int total = r;
        sort(arr.begin(), arr.end());
        while (start < n) {
            int k = arr[start];

            int count = 0;
            while (start < n && arr[start] == k  ) {
                start++;
                count++;
            }

            if (count > 1) {
                total += k * count;
                if (count % 2 == 1) {
                    total -= k;
                }
                if (total >= w)break;
            }
        }

        if (total >= w)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

}
