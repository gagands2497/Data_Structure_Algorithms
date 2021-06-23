#include <bits/stdc++.h>

using namespace std;

void IO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
equation of the form a*X + b*Y = gcd(a,b) X and Y must be integers
Then we can say (b)*x + (a%b)*y1 = gcd(b,a%b) = gcd(a,b) compare and find the 
X and Y in terms of x and y recursively

*/

class Triplet
{
public:
    int x, y, gcd;
};

Triplet Extended_Eucledian(int a, int b)
{
    if (b == 0)
    {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }

    Triplet smallAns = Extended_Eucledian(b, a % b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;

    return ans;
}

int main()
{
    IO();
    int a = 15, b = 10;
    Triplet ans = Extended_Eucledian(a, b);
    cout << ans.gcd << endl;
    cout << ans.x << endl;
    cout << ans.y << endl;
    return 0;
}