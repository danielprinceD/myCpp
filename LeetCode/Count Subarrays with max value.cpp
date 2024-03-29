#include <iostream>

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0 , n = nums.size() ;long long ans = 0;
        map<int , int> mp;
        int maxi = 0;
        for(auto i : nums) maxi = max(i , maxi);
        while(j < n)
        {
            mp[nums[j]]++;
            while( i <= j &&mp[maxi] >= k)
            {  
                ans += ( n-j);
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
