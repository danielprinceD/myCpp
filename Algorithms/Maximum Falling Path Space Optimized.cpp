#include <bits/stdc++.h>
using namespace std;


int maximumFallingPath(int i , int j , vector<vector<int>> &v)
{
    if(i < 0 || j < 0 || j >= v[0].size()) return -1e9;
    if(i==0)return v[0][j];
    
    int leftd = v[i][j] + maximumFallingPath(i-1 , j-1 , v);
    int rightd = v[i][j] + maximumFallingPath(i-1 , j+1 , v);
    int up = v[i][j] + maximumFallingPath(i-1 , j , v);
    
    return max(leftd , max(rightd , up));
}


int main()
{
    vector<vector<int>> v({
        {1 , 22 ,3 ,4},
        {12 , 10 ,3 ,4},
        {4000 , 20 ,36 ,600},
        {6 , 30 ,3 ,4},
    });
        
    int maxi = -1e9;

    for(int i=1;i<=v[0].size();i++)
    maxi = max(maxi , maximumFallingPath(v.size()-1 , v[0].size()-i , v) );
    
    int r = v.size() , c = v[0].size(); 
    
    vector<vector<int>> dp(r , vector<int> (c , 0) );
    
    for(int i=0;i<c;i++)
        dp[0][i] = v[0][i];
    
    
    vector<int> prev(c , 0);
    
    
    for(int i=1;i<r;i++)
    {
        vector<int> cur(c , 0);
        for(int j=0;j<c;j++)
        {
            int left , right , up;
            left = right = up = -1e9;
            if(j > 1)
                left = v[i][j] + prev[j-1];
            if(j+1 < c)
                right = v[i][j] + prev[j+1];
                
            up = v[i][j] + prev[j];
            
            
            cur[i] = max(left , max(up , right));
        }
        prev = cur;
    }
    for(int i=1;i<=c;i++)
     maxi = max(maxi , prev[c-i]);
    
    cout<<maxi;
    
    
    
    return 0;
}