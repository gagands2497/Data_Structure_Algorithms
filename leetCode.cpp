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
class Solution {
public:

    double power(double x, int n) {
        double ans = 1;
        while (n) {
            if (n % 2 == 0) {
                n /= 2;
                x *= x;
            } else {
                n--;
                ans *= x;
            }
        }
        return ans;
    }

    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        else if (n > 0) {
            return power(x, n);
        } else {
            n = -n;
            return (double)(1.0) / (double)(power(x, n));
        }
    }
};
//-----------------------------------------------------------------

//--------------------Main functions-------------------------------
int main()
{
    IO();
    Solution sol;

    cout << sol.myPow(2, -2) << endl;
}

//------------------Do calculatios here----------------------------