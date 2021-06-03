#include<bits/stdc++.h>

using namespace std;

void IO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void update(int index,int value,int *BIT,int n)
{
    for(;index<=n;index += (index&(-index)))
    {
        BIT[index] +=value;
    }
}

int query(int index,int *BIT)
{
    int sum = 0;
    for(;index > 0 ;index -= (index&(-index)))
    {
        sum += BIT[index];
    }
    return sum;
}

int main()
{
    IO();    
    int n;
    cin>>n;

    int *input = new int[n+1]();
    int *BIT=  new int[n+1]();//Binary index tree

    for(int i = 1;i<=n;i++)
    {
        cin>>input[i];
        update(i,input[i],BIT,n);
    }

    cout<<"sum of first 5 elements is "<<query(5,BIT)<<endl;
    /*
        we can also find the sum of a subarray like from 2 to 6
         = query(6) - query(1);
    */
    return 0;

}