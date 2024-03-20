#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int , int> mp;
        int longest = 0 , sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum = (nums[i]==1) ? sum + 1 : sum - 1;
            if(sum==0)
            {
                if(longest < i+1)
                    longest = i + 1;
            }
            else if(mp.find(sum) != mp.end())
            {
                longest = max ( longest , i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return longest;
    }
};

int main()
{
    vector<int> v{1 , 0 };
    Solution s;
    cout<<s.findMaxLength(v);
}
