#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusting(n+1,0) , trustedby(n+1,0);
        for(auto &a : trust)
        {
            ++trusting[a[0]];
            ++trustedby[a[1]];
        }
        for(int i=1;i<=n;i++)
            if(trusting[i]==0 && trustedby[i]==n-1)
                return i;
        return -1;
    }
};
int main()
{
    vector<vector<int>> v = {
        {1,3},{2,3}
    };
    Solution s;
    std::cout << s.findJudge(3, v) << std::endl;
    return 0;
}
