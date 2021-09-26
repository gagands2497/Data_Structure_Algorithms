#include <bits/stdc++.h>
using namespace std;

void IO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

#define ll long long
long long MOD = 1e9 + 7;
class Solution {
public:
    
    void merger(vector<int> &nums,vector<int> &temp,int start,int end){
        int mid = (start + end)/2;
        int i = start,j = mid+1,k  = start;
        
        while( i<=mid && j<=end){
            if(nums[i] < nums[j]){
                temp[k] = nums[i];
                k++;
                i++;
            }else{
                temp[k] = nums[j];
                k++;
                j++;
            }
        }
        
        while(i<=mid){
            temp[k++] = nums[i++];
        }
        
        while(j<=end){
            temp[k++] = nums[j++];
        }
        
        for(int i = start;i<=end;i++){
            nums[i] = temp[i];
        }
        return;
    }
    
    
    void merge_sort(vector<int> &nums,vector<int> &temp,int start,int end){
        if(start< end){
            int mid = (start + end)/2;
            
            merge_sort(nums,temp,start,mid);
            merge_sort(nums,temp,mid+1,end);
            
            merger(nums,temp,start,end);
        }
        return;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        int start = 0,end = n-1;
        
        merge_sort(nums,temp,start,end);
        
        return nums;
        
    }
};
int main()
{
    IO();
    Solution sol;
    vector<int> nums = {5, 4, 8, 7, 5, 6, 1, 8, 13, 5, 6, 5};
    vector<int> ans = sol.sortArray(nums) ;

    for(int i:ans){
        cout << i << " " ;
    }
}
