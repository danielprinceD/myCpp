#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int , int> freq;
        int ans =0, preSum =0;
        freq[0] = 1;
        for(auto &i : nums)
        {
            preSum+=i;
            if(freq.find(preSum - goal)!=freq.end()) ans+=freq[preSum-goal];
            freq[preSum]++;
        }
        return ans;
    }
};

int main()
{
    vector<int> v{0,0,0,0,0};
    Solution s;
    cout<<s.numSubarraysWithSum(v , 0);
    return 0;
}
