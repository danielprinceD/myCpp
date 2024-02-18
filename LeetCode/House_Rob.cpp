#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
    int dp[nums.size()+1];
    memset(dp,-1,sizeof dp);
    return helper(nums,nums.size()-1,dp);
        
    }   
    int helper(vector<int> &nums,int i,int dp[])
    {
        if(i < 0)return 0;
        if(dp[i]!= -1)return dp[i];
        dp[i] = max(helper(nums,i-1,dp) , nums[i] + helper(nums,i-2,dp));
        return dp[i];
    }
};
int main()
{
    vector<int> v = {1,2,3,1};
    Solution s;
    cout<<s.rob(v);
}
