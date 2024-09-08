#include<bits/stdc++.h>
using namespace std;


void brute(int n, vector<int> &v , int k)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        int sum = 0 ;
        for(int j=i;j<n;j++)
        {
            sum += v[j];
            if(sum == k)
            {
                count++;
                cout<<endl;
            }
        }
    }
    
    cout<<count;
    
    // T -> O(N^3)
    // S -> O(1)
    
}

void better(int n, vector<int> &v, int k)
{
    int preSum = 0 , count = 0;
    map<int , int>mp;
    mp[0] = 1;
    
    for(int it : v)
    {
        preSum += it;
        int rem = preSum - k;
        count += mp[rem];
        mp[preSum]+=1;
    }
    
    cout<<count;
    // T -> O(N * log N)
    // S -> O(N)
    
}

void optimal(int n , vector<int> &v)
{
}


int main(){
    vector<int> v({1, 2 , 3 , -3 , 1 ,1 , 1 , 4, 2 ,-3});
    int k = 3;
    better(v.size() , v , k);
}