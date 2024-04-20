#include <iostream>

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        for(int i=0;i<land.size();i++)
        {
            for(int j=0;j<land[0].size();j++)
            {
                if(land[i][j] == 1)
                {   
                    int r2 = i , c2 = j;
                    for(r2 = i ; r2 < land.size() && land[r2][j] ; r2++)
                        for(c2 = j; c2 < land[0].size() && land[r2][c2];c2++)
                            land[r2][c2] = 0;
                    ans.push_back({i , j , r2-1 , c2-1});
                }

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
