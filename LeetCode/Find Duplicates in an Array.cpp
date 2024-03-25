#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        map<int , int> mp;
        for(int i=0;i<nums.size();i++)
            if(++mp[nums[i]]==2)
                ans.push_back(nums[i]);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{1 ,2, 3 ,4 , 2 ,5 ,1};
    for(auto i : s.findDuplicates(v ))
        cout<<i<<" ";
}
