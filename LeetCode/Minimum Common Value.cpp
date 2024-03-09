#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0 , j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i] == nums2[j])
                return nums1[i];
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        return -1;
    }
};

int main()
{
    vector<int> v1{1,1,2};
    vector<int> v2{2 , 4};
    Solution s;
    cout<<s.getCommon(v1 , v2);
    return 0;
}
