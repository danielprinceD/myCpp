#include <iostream>

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j] == 0)
                    if(ans < abs(nums[i]))
                        ans = abs(nums[i]);
            }
        }
        return ans;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
