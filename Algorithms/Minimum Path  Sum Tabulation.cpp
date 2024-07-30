#include <bits/stdc++.h>
using namespace std;


int minimumPath(int i , int j , vector<vector<int>> &v )
{
    if(i < 0 || j < 0)return 1e9;
    if(i == 0 && j == 0)return v[i][j];
    int left = v[i][j] + minimumPath(i-1 , j , v);
    int right = v[i][j] + minimumPath(i  , j-1 , v);
    return min(left  , right);
}

int main()
{
    vector<vector<int>> v({
       {5 , 9 , 6}, 
       {1 , 5 , 2},
       {1 , 5 , 1},
    });
    
    vector<vector<int>> dp(v.size() , vector<int>(v[0].size() , 0) );
   
    int r = v.size();
    int c = v[0].size();
    
    vector<int> prev(c , 0);
    
    
    for(int i=0;i<r;i++)
    {
        
        vector<int> cur(c , 0);
        for(int j=0;j<c;j++)
        {
            int left = 1e9 , right = 1e9;
            if(i==0 && j == 0)
                cur[0] = v[0][0];
            else {
                if(i >= 1)
                left = v[i][j] + prev[j];
                if(j >= 1)
                right = v[i][j] + cur[j-1];
                cur[j] = min(left , right);
            }
        }
        prev = cur;
    }
    
    cout<<prev[c-1];
    
    return 0;
}