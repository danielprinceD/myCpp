#include <bits/stdc++.h>
using namespace std;

void dutch_nation_flag(auto &arr , int n)
{
    auto swap = [&](int i , int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    };
    int low = 0 , high = n - 1 , mid = 0;
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(low , mid);
            low++; mid++;
        }
        else if(arr[mid] == 1)
            mid++;
        else if(arr[mid] == 2)
        {
            swap(mid , high);
            high--;
        }
    }
    for(int i : arr)
        cout<<i<<" ";
}

int main()
{
    vector<int> arr({0 , 1, 1 ,0 , 1 , 2 , 1 , 2 ,0 , 0 , 0});
    dutch_nation_flag(arr , arr.size());
    return 0;
}