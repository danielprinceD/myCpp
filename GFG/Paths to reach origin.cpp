#include <iostream>
using namespace std;

class Solution
{
    public:
        int mod = 1e9+7;
        int steps(int x , int y , vector<vector<int>> &dp)
        {
            if(x==0 && y == 0)return 1;
            if(x < 0 || y < 0 )return 0;
            if(dp[x][y] != -1)return dp[x][y];
            return dp[x][y] = (steps(x-1 , y , dp) + steps(x , y-1 , dp))%mod;
        }
        int ways(int x, int y)
        {
            vector<vector<int>> dp(x+1 , vector<int> (y+1 , -1));
            return steps(x , y , dp);   
        }
};

int main()
{
    return 0;
}
