#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long total = totalSum(nums);
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(total - nums[i] > nums[i])return total;
            total-=nums[i];
        }
        return -1;
    }
    long long totalSum(vector<int> &nums)
    {
        long long total=0;
        for(auto i:nums)total+=i;
        return total;
    }
};
int main()
{
    Solution s;
    std::vector<int> v = {50,12,1,1,2,3,5};
    cout<<s.largestPerimeter(v);
}