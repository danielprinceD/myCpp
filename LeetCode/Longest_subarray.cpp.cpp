#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for(auto i=1;i<nums.size();i++)
            {
                for(auto j=0;j<i;j++)
                {
                    if(nums[i] > nums[j])
                    {
                        dp[i] = max(dp[i],dp[j]+1);
                    }
                }
            }
            return *max_element(dp.begin(),dp.end());
    }
};
int main()
{
    Solution s;
    vector<int> v = {10,9,2,5,3,7,101,18};
    cout<<s.lengthOfLIS(v);
    
    return 0;
}
