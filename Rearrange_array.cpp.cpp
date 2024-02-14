#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> arr;
        int k = 0;
        for(auto i : nums)
        {
            if(i > 0) 
            {
                arr.insert(arr.begin() + k , i);
            k++;
            }
        }
        k =1;
        for(auto i : nums)
        {
            if(i < 0){
            arr.insert(arr.begin() + k , i);
            k+=2;
            }
        }
        return arr;       
    }
};
int main()
{
    vector<int> v = {3,1,-2,-5,2,-4};
    Solution s;
    vector<int> a = s.rearrangeArray(v);
}
