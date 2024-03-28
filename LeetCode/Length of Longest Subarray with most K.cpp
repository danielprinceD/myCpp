#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0 , n = nums.size() , ans = 0;
        map<int , int> mp;
        while(j < n)
        {
            mp[nums[j]]++;
            while(i<=j && mp[nums[j]] > k)
            {
                mp[nums[j]]--;
                i++;
            }
            ans = max(ans , j-i+1);
            j++;
        }
        return ans;
    }
};

int main()
{
    vector<int> v{1 , 2 , 3 ,2 ,2};
    Solution s;
    cout<<s.maxSubarrayLength(v , 2);
}
