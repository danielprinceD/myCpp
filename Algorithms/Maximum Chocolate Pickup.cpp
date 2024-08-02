#include <bits/stdc++.h>
using namespace std;

int maximumChocolate(int i , int j1 , int j2 , vector<vector<int>> &v , int row , int col)
{
    if(j1 >= col || j2 >= col || i >= row || j1 < 0 || j2 < 0)
        return -1e9;

    if(i == row-1){
        if(j1==j2)return v[i][j1];
        else return v[i][j1] + v[i][j2];
    }
    
    int maxi = -1e9; 
    for(int d1=-1;d1<=1;d1++)
    {
        for(int d2=-1;d2<=1;d2++)
        {
            if(j1 == j2) 
                maxi = max(maxi , v[i][j1] + maximumChocolate(i+1 , j1+d1 , j2+d2 , v , row , col));
            else 
                maxi = max(maxi , v[i][j1] + v[i][j2] + maximumChocolate(i+1 , j1+d1 , j2+d2 , v , row , col));
        }
    }
    
    return maxi;
}

int main()
{
    
    
    vector<vector<int>> v({
        {1 , 2, 3 , 1},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
        {1 , 2, 3 , 7},
    });
    int r = v.size() , c = v[0].size();
    
    
    vector<vector<vector<int>>> dp(r , vector<vector<int>> (c , vector<int> (c , 0)));
    
    
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(j == i)
                dp[r-1][i][j] = v[r-1][j];
            else 
                dp[r-1][i][j] = v[r-1][j] + v[r-1][i];
        }
    }
    
    for(int i=r-2;i>=0;i--)
    {
        for(int j1=0;j1<c;j1++)
        {
            for(int j2=0;j2<c;j2++)
            {
                    int maxi = -1e9; 
                    
                    for(int d1=-1;d1<=1;d1++)
                    {
                        for(int d2=-1;d2<=1;d2++)
                        {
                            int value = 0;
                            if(j1 == j2 )
                                value = v[i][j1];
                            else value = v[i][j1] + v[i][j2];
                        
                            if(j1 + d1 < c && j2 + d2 < c && j1 + d1 >= 0 && j2 + d2 >= 0 )
                                value += dp[i+1][j1+d1][j2+d2];
                            else value += -1e8;
                            maxi = max(value , maxi);
                        }
                    }
                    dp[i][j1][j2] = maxi;
            }
        }
    }
    
    cout<<dp[0][0][c-1];
    
    return 0;
}