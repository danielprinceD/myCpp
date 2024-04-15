#include <iostream>

class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,int q) {
        int maxi = 0;
        maxi = max(*max_element(a.begin() , a.end()) , *max_element(b.begin() , b.end()));
        vector<int> ans(maxi + 1 , 0);
        for(int i=0;i<n;i++)ans[b[i]]++;
        for(int i=1;i<=maxi;i++)ans[i] += ans[i-1];
        vector<int> res;
        for(auto i : query)
            res.push_back(ans[a[i]]);
        return res;
    }
};

int main()
{
}
