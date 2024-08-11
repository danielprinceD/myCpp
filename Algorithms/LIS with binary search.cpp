#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++)
        if(arr[i] > temp.back())
            temp.push_back(arr[i]);
        else 
        {
            auto it = lower_bound(temp.begin() , temp.end() , arr[i] );
            *it = arr[i];
        }
        
    return temp.size();
}




int main()
{
    int arr[] = {1 , 7 ,8 ,4 , 5 ,6 ,-1 , 9};
    cout<<longestIncreasingSubsequence(arr , 8);
}