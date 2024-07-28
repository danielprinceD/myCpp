#include <bits/stdc++.h>
using namespace std;


void lcs(string &s1 , string &s2){
    int n = s1.size();
    vector<vector<int>> dp(n+1 , vector<int> (n+1 , -1));
    for(int i=0;i<n;i++)dp[i][0] = 0;
    for(int i=0;i<n;i++)dp[0][i] = 0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    
    int i , j; i = j = n;
    string str = "";
    while(i >= 0 && j >= 0)
    {
        if(s1[i] == s2[j])
        {
            str = s1[i] + str;
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else j--;
    }
    cout<<str;
}

int main()
{
    string str = "bbabcbcab";
    string rev = str;
    reverse(rev.begin() , rev.end());
    lcs(str , rev);
    return 0;
}