#include <bits/stdc++.h>
using  namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix.size();
        vector<vector<int>> dp = matrix;
        for(int i=0;i<n;i++)
        {
            for(int j=0; j < m; j++)
            {
                int mini = INT_MAX;
                for(int tryj=0; i-1 >= 0 && tryj < m ; tryj++)
                {
                    if(tryj == j )continue;
                    mini = min(mini , dp[i-1][tryj]);
                }
                    dp[i][j] += (INT_MAX == mini) ? 0 : mini;
            }
        }
        return *min_element(dp[n-1].begin() , dp[n-1].end());
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
