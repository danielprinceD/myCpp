#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int , int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>1)return nums[i];
        }
        return -1;
    }
};

int main()
{
    vector<int> nums{1 , 2 ,3, 3};
    Solution s;
    cout<<s.findDuplicate(nums);
}
