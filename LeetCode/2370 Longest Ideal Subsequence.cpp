#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solver(int i , char last , string &s, int k , vector<vector<int>> &dp)
    {
        if(i == s.size() )return 0;
        if(dp[i][last-'a'] != -1)return dp[i][last-'a'];
        
        int take = 0 , not_take = 0;
        
        if(last == '{' || abs(s[i] - last) <= k)
            take = 1 + solver(i+1 , s[i] , s , k , dp);
        not_take = solver(i + 1 , last , s , k , dp);
        
        return dp[i][last-'a'] = max(take , not_take);
    }
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.size() , vector<int> (27 , -1));
        return solver(0,'{', s , k , dp);
    }
};

int main()
{
    Solution s;
    cout<<s.longestIdealString("pvjcci" , 4);
    return 0;
}
