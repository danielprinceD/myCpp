#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(vector<int>&nums,int target,int dp[])
    {
        if(dp[target] != 0) return dp[target] ;
        if(target == 0) return 1;
        
        for(int i=0;i<nums.size() && target >= nums[i];i++)
                dp[target] += helper(nums,target-nums[i],dp);
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        int dp[target+1];
        memset(dp,0,sizeof dp);
        return helper(nums,target,dp);
    }
};
int main()
{
    vector<int> v = {1,2,3};
    Solution s;
    cout<<s.combinationSum4(v,4);
    return 0;
}
