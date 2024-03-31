#include <iostream>
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size(), min_i = -1 , max_i = -1 , bad_i = -1;
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] > maxK || nums[i] < minK)bad_i = i;
            if(nums[i] == minK) min_i = i;
            if(nums[i] == maxK) max_i = i;
            ans += max(0 , min(max_i , min_i) - bad_i );
        }
        
        return ans;
    }
};
int main()
{
    std::cout<<"Hello World";

    return 0;
}
