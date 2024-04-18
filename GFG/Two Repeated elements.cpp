#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> twoRepeated (int arr[], int n) {
        vector<int>ans;
        map<int, int > mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            if(mp[arr[i]] == 2)ans.push_back(arr[i]);
        }
        return ans;
    }
};

int main()
{
    int arr[] =  {1 ,2 ,1 ,3 ,4 ,3};
    Solution s;
    for(auto i : s.twoRepeated(arr , 6))cout<<i<<" ";
}
