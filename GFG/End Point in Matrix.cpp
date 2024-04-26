#include <bits/stdc++.h>
using  namespace std;

class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        bool left = 0 , right = 1 , up = 0 , down = 0;
        int last_i = 0 , last_j = 0;
        int i = 0, j = 0;
        while( i < n &&  j < m && i >= 0 && j >= 0)
        {
            if(matrix[i][j]){
                
                if(right){
                    right = 0; down = 1; up = 0 , left = 0;
                    matrix[i][j] = 0;
                    last_i = i; last_j = j;
                    i++;
                }else 
                if(down){
                    right = 0; down = 0; up = 0 , left = 1;
                    matrix[i][j] = 0;
                    last_i = i; last_j = j;
                    j--;
                }else 
                if(up){
                    right = 1; down = 0; up = 0 , left = 0;
                    matrix[i][j] = 0;
                    last_i = i; last_j = j;
                    j++;
                }else
                if(left){
                    right = 0; down = 0; up = 1 , left = 0;
                    matrix[i][j] = 0;
                    last_i = i; last_j = j;
                    i--;
                } 
            }
            else{
                
                if(right){
                    last_i = i; last_j = j;
                    j++;
                }
                if(down){
                    last_i = i; last_j = j;
                    i++;
                }
                if(up){
                    last_i = i; last_j = j;
                    i--;
                }
                if(left){
                    last_i = i; last_j = j;
                    j--;
                }
            }
            
            
        }
        vector<int> ans = {last_i , last_j};
        return ans;
    }
};


int main()
{
    vector<vector<int>> v{
            {0, 1, 0},
          {0, 1, 1}, 
          {0, 0, 0}};
    Solution s;
    for(auto i : s.FindExitPoint(3 , 3, v))cout<<i << " ";
}
