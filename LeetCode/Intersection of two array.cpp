#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());
        
        int i = 0,  j = 0;
        set<int> st;vector<int> ans;
         while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                st.insert(nums1[i]);
                i++;j++;
            }
            else if(nums1[i] < nums2[j])
                i++;
            else j++;
                
        }
        for(auto i : st)ans.push_back(i);
        return ans;
        
    }
};

int main()
{
    vector<int> v1{4,9,5};
    vector<int> v2{9,4,9,8,4};
    Solution s;
    vector<int>v3 = s.intersection(v1 , v2);
    for(auto i : v3)
        cout<<i<<" ";
    return 0;
}
