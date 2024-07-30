#include <bits/stdc++.h>
using namespace std;


int uniquePath(int m , int n , vector<vector<int>> &v ,vector<vector<int>> &dp  )
{
    if(m < 0 || n < 0 || v[m][n] == -1)return 0;
    if(m == 0 && n == 0)return 1;
    if(dp[m][n] != -1)return dp[m][n];
    return dp[m][n] = uniquePath(m-1 , n ,v , dp) + uniquePath(m , n -1 ,v , dp);
    
}

int main()
{
    vector<vector<int>> v({
       {0 , 0 , 0}, 
       {-1 , 0 , 0},
       {0 , 0 , 0},
    });
    
    int m = v.size(), n = v[0].size();
    vector<vector<int>> p(m , vector<int > (n , -1));
    
    vector<vector<int>> dp(m+1 , vector<int > (n+1 , 0));
    
    vector<int> row(m , 0);
    
    for(int i=0;i<m;i++)
    {
        vector<int> temp(n , 0);
    
        for(int j=0;j<n;j++)
        {
            if(v[i][j] == -1){
                temp[j] = 0;
            }else if(i == 0 && j == 0 ) temp[0] = 1;
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