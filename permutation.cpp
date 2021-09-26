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

void permute(vector<bool> &used,vector<int> &nums,vector<vector<int>> &permutations,vector<int> permutation){
    int n = nums.size();
    int m = permutation.size();
    if(m == n){
        // process the permutation
        permutations.push_back(permutation);
    }else{

        for (int i = 0; i < n;i++){
            if(used[i] == false){
                used[i] = true;
                permutation.push_back(nums[i]);
                permute(used, nums, permutations, permutation);
                permutation.pop_back();
                used[i] = false;
            }
        }
    }
}

int main()
{
    IO();

    vector<int> nums = {1,2,3};
    int n = nums.size();
    vector<int> permutation;
    vector<vector<int>> permutations;
    vector<bool> used(n,false);
    permute(used,nums,permutations,permutation);
    for( auto v : permutations){
        for(int x : v){
            cout << x << " ";
        }
        cout << endl;
    }
}