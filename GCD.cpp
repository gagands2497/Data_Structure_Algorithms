#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    if(b == 0)
    {
        return a;
    }

    int r = a%b;
    //value of r is in the range of 0 to b-1
    //r = a%b = a - b*[a/b] //floor value of a/b 
    return gcd(b,r);
}

int main()
{
    cout<<gcd(10,20)<<endl;
}