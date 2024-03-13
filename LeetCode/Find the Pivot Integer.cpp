#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        vector<int> v(n+1 , 0);
        for(int i=1;i<=n;i++)
            v[i] += i + v[i-1];
        int sum =0;
        while(n > 0)
        {
            sum+=n;
            if(v[n] == sum)
                return n;
            n--;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout<<s.pivotInteger(8);
    return 0;
}
