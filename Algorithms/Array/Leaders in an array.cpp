#include<bits/stdc++.h>
using namespace std;

void brute(int n , vector<int> &v)
{
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        bool flag = 1;
        for(int j=i+1;j<n;j++)
        {
            if(v[i] < v[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        cout<<v[i]<<" ";
    }
    
    // T - O(N^2)
    // S - O(1)
}

void optimal(int n , vector<int> &v)
{
    vector<int> ans;
    int maxi = -1e9;
    for(int i=n-1;i>=0;i--)
    {
        if(maxi < v[i])
        {
            maxi = v[i];
            cout<<v[i]<<" ";
        }
    }
    
    // T -> O(N)
    // S -> O(1)
}


int main(){
    vector<int> v({10 , 22 , 12 , 3 , 0 , 6});
    optimal(v.size() , v);
}