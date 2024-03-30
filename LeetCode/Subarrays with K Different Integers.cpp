#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMost(vector<int>& nums, int k)
    {
         int i=0, n= nums.size() , j=0 , ans = 0;
        map<int , int> mp;
        while(j < n)
        {
            mp[nums[j]]++;
            while(i <= j && mp.size() > k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       
        return atMost(nums , k ) - atMost(nums , k-1);
    }
};

int main()
{
    Solution s;
    vector<int> v{1,2,1,2,3};
    cout<<s.subarraysWithKDistinct(v , 2);
}
