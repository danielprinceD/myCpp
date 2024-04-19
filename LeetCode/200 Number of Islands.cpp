#include <iostream>

class Solution {
public:
    void dfs(int i,int j , vector<vector<char>>& grid)
    {
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(i , j+1 , grid);
        dfs(i+1 , j , grid);
        dfs(i , j-1 , grid);
        dfs(i-1 , j , grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i , j , grid);
                    island++;
                }
            }
        }
        return island;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
