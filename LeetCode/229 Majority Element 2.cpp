#include <iostream>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int limit = nums.size()/3+1;
        map<int , int > mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] == limit)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};

int main()
{
}
