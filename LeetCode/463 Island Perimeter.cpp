#include <iostream>
using namespace std;

class Solution {
public:
    int solver(int i , int j , vector<vector<int>>& grid)
    {
        int peri = 4;
        peri -= (i+1 < grid.size()) ? (grid[i+1][j] == 1) ? 1 : 0 : 0;
        peri -= (j+1 < grid[0].size()) ? (grid[i][j+1] == 1) ? 1 : 0 : 0;
        peri -= (i-1 >= 0 ) ? (grid[i-1][j] == 1) ? 1 : 0 : 0;
        peri -= (j-1 >= 0 ) ? (grid[i][j-1] == 1) ? 1 : 0 : 0;
        return peri;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==1)
                perimeter += solver(i , j , grid);
        return perimeter;
    }
};

int main()
{
}
