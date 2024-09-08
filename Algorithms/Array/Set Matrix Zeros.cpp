#include<bits/stdc++.h>
using namespace std;

void printer(auto v)
{
    for(auto row : v)
    {
        for(auto ele : row)
        cout<<ele<<" ";
        cout<<endl;
    }
}

void brute(int n , int m, vector<vector<int>> &v)
{
    auto set_row_zero = [&](int i , int j){
        for(int i=0;i<n;i++)
        if(v[i][j] != 0)
            v[i][j] = -1;
    };
    auto set_col_zero = [&](int i , int j){
        for(int j=0;j<n;j++)
            if(v[i][j] != 0)
                v[i][j] = -1;
    };
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j] == 0)
            {
                set_row_zero(i, j);
                set_col_zero(i, j);
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(v[i][j] == -1)
                v[i][j] = 0;
    
    printer(v);
    // T -> O(N^3)
    // S -> O(1)
    
}

void better(int n , int m, vector<vector<int>> &v)
{
    vector<int> marked_row(n , 0) , marked_col(m , 0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j] == 0)
            {
                marked_row[i] = 1;
                marked_col[j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(marked_row[i] == 1 || marked_col[j] == 1)
                v[i][j] = 0;
        }
    }
    
    printer(v);
    
    // T -> O(2 * N * M)
    // S -> O(N + M)
    
}

void optimal(int n , int m, vector<vector<int>> &v)
{
    int col_0 = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j] == 0)
            {
                v[i][0] = 0;
                if(j != 0)
                    v[0][j] = 0;
                else 
                    col_0 = 0;
            }
        }
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(v[i][j] != 0)
            {
                if(v[0][j] == 0 || v[j][0] == 0)
                    v[i][j] = 0;
            }
        }
    }
    
    if(v[0][0] == 0)
        for(int j=0;j<m;j++)
            v[0][j] = 0;
    
    if(col_0 == 0)
        for(int i=0;i<n;i++)
            v[i][0] = 0;
    
    printer(v);
    
    
    // T -> O(2 * N * M  +  N + M )
    // S -> O(1)
    
}


int main(){
    vector<vector<int>> v({
        {1 , 1, 1 , 1,} , 
        {1 , 0, 1 , 1,} , 
        {1 , 1, 0 , 1,} , 
        {1 , 0, 0 , 1,} 
    });
    optimal(v.size() , v[0].size() , v);
}