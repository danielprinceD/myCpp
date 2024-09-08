#include<bits/stdc++.h>
using namespace std;

void powerSet(string &s )
{
    int n = s.length() , end = (1<<n)-1;
    for(int num=0;num<=end;num++)
    {
        string temp = "";
        for(int i=0;i<n;i++)
            if(num & (1 << i))
                temp+= s[i];
        cout<<temp<<" ";
    }
}

int lcs(int i , int j , string &a , string &b , vector<vector<int>> &dp)
{
    if(i >= a.length() || j >= b.length())
        return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(a[i] == b[j])
        return dp[i][j] =  1 + lcs(i+1 , j+1 , a , b ,dp);
    return dp[i][j] = max ( lcs(i , j + 1 , a , b, dp) ,  lcs(i +1 , j , a , b , dp) );
}

int main(){
    string s1 = "acbgj";
    string s2 = "cbeacbgiacbg";
    vector<vector<int>> dp(s1.length() , vector<int>( s2.length(), -1));
    cout<<lcs(0 , 0  , s1 , s2 , dp);
    
}