#include <iostream>

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        vector<vector<int>> ans(grid.size()-2 , vector<int> (grid.size()-2 , INT_MIN));
        for(int i=1;i<=grid.size()-2;i++)
        {
            for(int j=1;j<=grid.size()-2;j++)
            {
                int temp = 0;
                for(int k=i-1;k<=i+1;k++)
                {   
                    for(int l=j-1;l<=j+1;l++)
                    {
                        temp = max(temp , grid[k][l]);
                    }
                }
                ans[i-1][j-1] = temp;
            }
        }
        return ans;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
