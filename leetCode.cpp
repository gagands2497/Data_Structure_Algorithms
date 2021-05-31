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

void printVector(vector<int> nums,int number)
{
    cout<<"Vector number is "<<number<<endl;
    for(int i : nums)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int ,int> M;

        vector<int> ans;

        for(int i = 0;i<n;i++)
        {
            
            int k = M[target - nums[i]] - 1;
            if(M[target - nums[i]] )
            {
                ans.push_back(i);
                ans.push_back(M[target - nums[i]] - 1);
                if(ans[0] == ans[1])continue;
                else return ans;
            } 
            M[nums[i]] = i + 1;
        }
        return ans;

    }
};

//-----------------------------------------------------------------


//--------------------Main functions-------------------------------
int main()
{
    IO();
    Solution sol;
    vector<int> nums = {2,5,5,11};
    int target = 10;

    vector<int> ans = sol.twoSum(nums,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}

//------------------Do calculatios here----------------------------