#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        if(nums.size() ==1)return 0;
        int score = nums[0] + nums[1];
        int i=2,count = 1;
        while(nums.size() > i && nums.size()-i-1 >= 1)
        {
            int nowScore = nums[i+1] + nums[i];
            if(nowScore == score)
            {
            i+=2;
            count++;   
            }
            else break;
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> v = {1,2,3,0,1,2};
    cout<<s.maxOperations(v);
}