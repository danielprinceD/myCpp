#include <bits/stdc++.h>
using  namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        vector<vector<int>> dp(matrix.size() , vector<int> (matrix[0].size() , -1));
        int m = matrix.size() , n = matrix[0].size();
        for(int i=0;i<n;i++)dp[0][i] = matrix[0][i];
        
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int mini = INT_MAX;
                mini = min(mini , dp[i-1][j]);
                if(j + 1 < n)mini = min(mini , dp[i-1][j+1]);
                if(j-1 >= 0) mini = min(mini , dp[i-1][j-1]);
                
                dp[i][j] = mini + matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++) ans = min ( ans , dp[n-1][i]);
        
        return ans;
    }
};

int main()
{
    vector<vector<int>> v{
        {2,1,3},{6,5,4},{7,8,9}
    };
    Solution s;
    cout<<s.minFallingPathSum(v);
}
