#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int , int> mp;
        int maxi = 0 , tot=0;
        for(auto i : nums)
        {
            mp[i]++;
            if(maxi < mp[i])
            {
                tot = 0;
                maxi = mp[i];
                tot+=maxi;
            }
            else if(maxi == mp[i])
                tot+=maxi;
            
        }
        return tot;
    }
};

int main()
{
    Solution s;
    vector<int> v{1,2,2,3,1,4};
    cout<<s.maxFrequencyElements(v);
}
