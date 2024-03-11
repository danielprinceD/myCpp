#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        map<char , int> mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        string ans="";
        for(int i=0;i<order.size();i++)
        {
            while(mp[order[i]] > 0)
            {
                ans+=order[i];
                mp[order[i]]--;
            }
        }
        for(auto &i : mp)
        {
            while(i.second > 0)
            {
                ans+=i.first;
                i.second-=1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout<<s.customSortString("bcafg" , "abcd");
    
    return 0;
}
