#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int> (text2.length()+1,-1));
        return recursion(0,0,text1,text2,dp);
    }
    int recursion(int i,int j, string text1,string text2,vector<vector<int>>&dp)
    {
        if(dp[i][j]==-1)
        {
        if(text1[i] == '\0' || text2[j]=='\0')
            dp[i][j] = 0;
        else if (text1[i] == text2[j] )
            dp[i][j] =  1 + recursion(i+1,j+1,text1,text2,dp);
        else
            dp[i][j] =  max(recursion(i+1,j,text1,text2,dp),recursion(i,j+1,text1,text2,dp));
        }
        return dp[i][j];
}
};

int main()
{
    Solution s;
    cout<<s.longestCommonSubsequence("abcd" , "acde");
}