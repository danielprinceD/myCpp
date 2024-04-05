#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int min_operations(vector<int>& nums) {
        int  n=nums.size();
        vector<int> dp(n , 1 );
        
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j] && nums[i] - nums[j] >= i-j )
                    dp[i] = max(dp[i] , 1 + dp[j]);
            }
        }
        int maxi = 0;
        for(int i=0;i<n;i++)maxi = max(dp[i] , maxi);
        return n - maxi;
    }
};



int main()
{
}
