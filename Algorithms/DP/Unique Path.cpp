#include <bits/stdc++.h>
using namespace std;


int uniquePath(int m , int n , vector<vector<int>> &dp)
{
    if(m == 1 && n == 1)return 1;
    if(m <= 0 || n <= 0)return 0;
    if(dp[m][n] != -1)return dp[m][n];
    return dp[m][n] = uniquePath(m-1 , n ,dp) + uniquePath(m , n -1 , dp);
    
}

int main()
{
    int m = 5 , n = 5;
    vector<vector<int>> dp(m+1 , vector<int > (n+1 , 0));
    
    dp[0][0] = 1;
    
    
    vector<int> row(m , 0);
    
    for(int i=0;i<m;i++)
    {
        vector<int> temp(n , 0);
    
        for(int j=0;j<n;j++)
        {
            if(i == 0 && j == 0 ) temp[0] = 1;
            else {
                
            int left = 0 , right = 0;
            if(i >= 1)left = row[i-1];
            if(j >= 1)right = temp[j-1];
            temp[j] = left + right;
            }
        }
        row = temp;
    }
    cout<<row[m-1];
    return 0;
}