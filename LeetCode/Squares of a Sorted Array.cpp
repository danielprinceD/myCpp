#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)nums[i]=nums[i]*nums[i];
        sort(nums.begin() , nums.end());
        return nums;
    }
};

int main()
{
    vector<int> v = {
        -7,-3,2,3,11
    };
    Solution s;
    vector<int> ans = s.sortedSquares(v);
    for(auto i : ans)cout<<i<<" ";
}
