#include <bits/stdc++.h>
using namespace std;

bool possible(int i , int j , string &a , string &b)
{
    if(i < 0 && j < 0)return true;
    
    if(i < 0 && j >= 0)return false;
    
    if(j < 0 && i >= 0)
    {
       for(int ii=0;ii<=i;ii++)
         if(a[ii] != '*')
            return false;
        return true;
    }
    
    if(a[i] == b[j] || a[i] == '?')
        return possible(i-1 , j-1 , a ,b);
    if(a[i] == '*')
        return possible(i-1 , j , a ,b ) | possible(i , j-1 , a , b);
    return false;
}

bool wildcardMatching(string pattern, string text)
{
    int  n = pattern.length() , m = text.length();
    
    vector<vector<bool>> dp(n+1 , vector<bool> (m+1 , 0));
    
    dp[0][0] = 1;
    
    for(int i=1;i<=n;i++)
    {
        int flag = 1;
        for(int ii=1;ii<=i;ii++)
            if(pattern[ii-1] != '*')
            {
                flag = 0;
                break;
            }
        dp[i][0] = flag;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?')
                dp[i][j] = dp[i-1][j-1];
            else if(pattern[i-1] == '*')
                dp[i][j] = dp[i-1][j] | dp[i][j-1];
        }
    }
    
    return dp[n][m];
}


int main()
{
    string str = "ab*cd" , str2 = "abdejcd";
    cout<<wildcardMatching(str , str2);
    return 0;
}