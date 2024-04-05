#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        for(int i=0;i<s.size()-1;i++)
            if(abs(s[i] - s[i+1] == 32))
               return makeGood(s.substr(0 , i ) + s.substr(i+2));
        return s;
    }
};



int main()
{
    Solution s;
    cout<<s.makeGood("leEeetcode");
}
