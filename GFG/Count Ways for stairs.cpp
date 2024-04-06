#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long countWays(int n) {
        vector<long long> dp(n+1 , 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++)
            dp[i] = 1 + dp[i-2];
        return dp[n];
    }
};



int main()
{
}
