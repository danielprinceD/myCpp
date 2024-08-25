#include <bits/stdc++.h>
using namespace std;
int countSquares(int n, int m, vector<vector<int>> &arr) {
    vector<vector<int>> dp(n , vector<int> (m , 0));
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        dp[i][0] = arr[i][0];
        ans += dp[i][0];
    }

    for(int i=1;i<m;i++)
    {
        dp[0][i] = arr[0][i]; 
        ans += dp[0][i];
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j] == 1)
            {
            int minVal = min(dp[i][j-1] , min(dp[i-1][j-1] , dp[i-1][j]) );
            dp[i][j] = 1 + minVal;
            ans += dp[i][j];
            }
        }
    }
    for(auto i : dp)
    {
        for(int j : i)
            cout<<j<<" ";
        cout<<endl;
    }
    return ans;
}
int main()
{
    int n , m; cin>>n>>m;
    vector<vector<int>> mat(n , vector<int> (m , 0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>mat[i][j];
    cout<<countSquares(n , m , mat);
}