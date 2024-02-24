#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int solver(int i, int j ,string s , string t,int n , int m,vector<vector<int>> &dp)
    {
        if(j==m)return 1;if(i==n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]!=t[j])return dp[i][j] = solver(i+1 , j , s , t ,n , m , dp);
        return dp[i][j] = solver(i+1 , j + 1 , s , t , n , m , dp ) + solver(i+1 , j , s , t ,n , m , dp) ;
    }
    int numDistinct(string s, string t)
    {
      int n = s.size();
      int m = t.size();
      vector<vector<int>> dp(n ,vector<int>(m , -1));
      return solver(0 , 0 , s , t , n , m , dp );
    }
};
int main()
{
    Solution s;
    cout<<s.subsequenceCount("rabbbit","rabbit");
  
}

