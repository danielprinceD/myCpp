#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin() , s.rend());
        for(int i=s.size()-1;i>=0;i--)
            if(s[i]=='1')
            {
                s[i] = '0';
                s[s.size()-1] = '1';
                break;
            }
        return s;
    }
};

int main()
{
    Solution s;
    cout<<s.maximumOddBinaryNumber("001001111");
    return 0;
}
