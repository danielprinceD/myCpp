#include <bits/stdc++.h>
using namespace std;

// MAXIMUM SUBARRAY SUM;

void brute(int n , vector<int> &v)
{
    int ans = -1e9;
    for(int i=0;i<n;i++)
    {
        int sum = 0;
        for(int j=i;j<n;j++)
        {
            sum += v[j];
            ans = max(ans , sum);
        }
    }
    cout << ans;
    
    // T - O(N^2)
    // S - O(1)
}

void better(int n , vector<int> &v)
{
    int maxi = -1e9 , sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += v[i];
        maxi = max(maxi , sum);
        if(sum < 0)
            sum = 0;
    }
    cout<<maxi;
    
    // T - O(N)
    // S - O(1)   
}

void optimal(int n , vector<int> &v)
{
    int maxi = -1e9 , sum = 0;
    int ansStart = -1 , ansEnd = -1 , start;
    for(int i=0;i<n;i++)
    {
        if(sum == 0)
            start = i;
        sum += v[i];
        if(sum > maxi)
        {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0)
            sum = 0;
    }
    
    cout<<"Array : ";
    for(int i=ansStart;i<=ansEnd;i++)
    cout<<v[i]<<" ";
    
    cout<<endl<<"Maximum Value : "<<maxi;
    
    // T - O(N)
    // S - O(1)
}



int main()
{
    vector<int> v = {-2 , -3 , 4 , -1 , -2, 5 , 1 , -3};
    optimal(v.size() , v);
}