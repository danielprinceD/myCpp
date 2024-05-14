#include <iostream>

class Solution {
public:
    vector<int> dx = {-1 , 0 , 0 , 1};
    vector<int> dy = {0 , -1 , 1 , 0};
    int dfs(int i, int j , int n , int m , vector<vector<int>>& grid)
    {
        if(i>=n || j >= m || i < 0 || j < 0 ||  grid[i][j] == 0)return 0;
        int maxSum = 0 , curVal = grid[i][j];
        for(int d=0;d<4;d++)
        {
            int ni = i+dx[d] , nj = j + dy[d];
            grid[i][j] = 0;
            maxSum = max(maxSum , curVal + dfs(ni , nj , n , m , grid));
            grid[i][j] = curVal;
        }
        return maxSum;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maximum = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    maximum = max(maximum , dfs(i , j , n ,  m , grid ));
                }
            }
        }
        return maximum;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
