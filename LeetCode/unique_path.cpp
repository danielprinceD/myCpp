#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector <int>> dp(m , vector<int>(n,-1));
        dp[0][0] = 1;
        return ways(m-1 , n-1 ,dp);
    }
    int ways(int m ,int n , vector<vector <int>> &dp)
    {
        if(m < 0 || n < 0) return 0;
        if(m == 0 && n == 0 ) return 1;
        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }
        dp[m][n] = ways(m-1,n,dp) + ways(m , n-1,dp);
        return dp[m][n];
    }
};
int main()
{
  Solution s;
  cout<<s.uniquePaths(3,3);
    return 0;
}
