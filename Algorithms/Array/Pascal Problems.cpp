#include<bits/stdc++.h>
using namespace std;


void nCr(int n , int r)
{
    int ans = 1;
    for(int i=0;i<r;i++)
        ans = ans * (n - i) / (i + 1);
    cout<<ans<<" "; 
}

void nthPascal(int c)
{
    // BRUTE : 
    /*for(int i=1;i<=c;i++)
        nCr(c-1 , i-1);*/
    
    // OPTIMAL : 
    int ans = 1;
    cout<<ans<<" ";
    
    for(int col=1;col<c;col++)
    {
        ans = ans * (c - col) / col;
        cout<<ans<<" ";
    }
    
}


void pascalTriangle(int size)
{
    for(int n=1;n<=size;n++)
    {
        int ans = 1;
        for(int i=n;i<size;i++)
            cout<<" ";
        for(int r=1;r<=n;r++)
        {
            cout<<ans<<" ";
            ans = ans * (n-r) / r;
        }
        cout<<endl;
    }
}

int main(){
    pascalTriangle(6);
}