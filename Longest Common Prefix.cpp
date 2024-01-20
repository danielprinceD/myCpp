#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string ans="";
        int n=strs.size();
        string first = strs[0],last = strs[n-1];
        for(int i=0;i<min(first.size(),last.size());i++)
        {
            if(first[i]!=last[i])
            {
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};
int main()
{
    
    vector<string> strs = {"hello","helmm","helnn"};
    Solution s;
    cout<<s.longestCommonPrefix(strs);
}
