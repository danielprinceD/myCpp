#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int i = digits.size()-1;
        int carry = 1 , add;
        while(i >= 0 )
        {
            add = carry + digits[i];
            carry = add / 10;
            ans.push_back(add%10);
            i--;
        }
        if(carry!=0)
            ans.push_back(carry);
        reverse(ans.begin() , ans.end());
        return ans; 
    }
};

int main()
{
    Solution s;
    
}
