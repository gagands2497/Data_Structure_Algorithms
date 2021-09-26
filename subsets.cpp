#include <bits/stdc++.h>
using namespace std;
#define ll long long

void IO()
{
#ifndef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void make_subsets(vector<int> &nums,int i,int n,vector<vector<int>> &subsets,vector<int> subset){

    if(i == n){
        // Process the subset
        subsets.push_back(subset);
    }
    else{
        subset.push_back(nums[i]);
        // include the nums[i] in subset
        make_subsets(nums,i+1,n,subsets,subset);
        subset.pop_back();
        // don't include nums[i] in subset
        make_subsets(nums,i+1,n,subsets,subset);
    }
}

int main()
{
    IO();
    vector<int> nums = {1,2,3};

    vector<vector<int>> ans;
    vector<int> subset;
    make_subsets(nums, 0, nums.size(), ans, subset);

    for(auto v : ans){
        for(int k : v){
            cout << k << " ";
        }
        cout << endl;
    }
}