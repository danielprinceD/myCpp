#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int prev =1,cur = 1;
        for(int i=2;i<=n;i++)
        {
            cur^=prev^=cur^=prev;
            cur = prev + cur;
        }
        return cur;
    }
};

int main()
{
    Solution s;
    cout<<s.climbStairs(4);
}