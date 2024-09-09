#include<bits/stdc++.h>
using namespace std;

void brute(int n , vector<int> &v , int target)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        int sum = 0;
        for(int j=i;j<n;j++)
        {
            sum ^= v[j];
            if(sum == target)
                count++;
        }
    }
    cout<<count;
    
    // T -> O(N^2)
    // S -> O(1)
    
}

void optimal(int n , vector<int> &v , int target)
{
    int preSum(0) , count(0);
    map<int , int > mp;
    mp[preSum]++;
    for(int i=0;i<n;i++)
    {
        preSum ^= v[i];
        int removed = preSum ^ target;
        count += mp[removed];
        mp[preSum]++;
    }
    cout<<count;
    
    // T  ->  O(N) + O(NlogN)
    // S  ->  O(N)
    
}


int main(){
    vector<int> v({4, 2 , 2 , 6 , 4});
    optimal(v.size() , v , 6);
}