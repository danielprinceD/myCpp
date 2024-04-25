#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        if(n < 3 || m < 3) return -1;
        int ans = 0;
        for(int i=0;i<=n-3;i++)
            for(int j=0;j<=m-3;j++)
                ans = max(ans , mat[i][j] + mat[i][j+1] + mat[i][j+2] + mat[i+1][j+1] + mat[i+2][j] + mat[i+2][j+1] + mat[i+2][j+2]);
        return ans;
        
    }
};


int main()
{
}
