// Multiplicative modulo inverse

#include <bits/stdc++.h>

using namespace std;

void IO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Triplet
{
public:
    int x, y, gcd;
};

Triplet MMI(int a, int m)
{
    if (m == 0)
    {
        Triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    Triplet smallAns = MMI(m, a % m);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / m) * smallAns.y;
    return ans;
}

int main()
{

    int a = 5, m = 17;
    Triplet ans = MMI(a, m);
    cout << ans.x << endl;
    return 0;
}