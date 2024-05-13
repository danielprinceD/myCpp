#include <iostream>

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            if(grid[i][0] == 0)
            {
                for(int j=0;j<grid[i].size();j++)
                {
                    grid[i][j] ^= 1;
                }
            }
        }

        for(int j=1;j<grid[0].size();j++)
        {
            int colCount = 0;
            for(int i=0;i<grid.size();i++)
                colCount+=grid[i][j];
            if(colCount < grid.size()-colCount)
            {
                for(int i=0;i<grid.size();i++)
                    grid[i][j] ^= 1;
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            int sum = 0;
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j] == 1)
                sum += pow(2 , grid[0].size()-j-1);
            ans += sum;
        }
        return ans;

    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
