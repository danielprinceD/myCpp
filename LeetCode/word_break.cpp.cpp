#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int pos,string str,set<string> &st,int dp[])
    {
        if(pos == str.size())return 1;
        if(dp[pos]!=-1)return dp[pos];
        string temp;
        for(int i=pos;i<str.size();i++)
        {
            temp += str[i];
            if(st.find(temp) != st.end() && helper(i+1, str,st,dp)==1)
                return dp[i] = 1;
            
        }
        return dp[pos] = 0;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int dp[s.length()+1];
        memset(dp,-1,sizeof dp);
        set<string> st;
        for(auto i:wordDict)st.insert(i);
        return helper(0,s,st,dp);
    }
};
int main()
{
    vector<string> wordDict = {"new","book"};
    Solution s;
    cout<<s.wordBreak("newbook",wordDict);
    return 0;
}