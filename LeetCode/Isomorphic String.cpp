#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char , char> mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp[s[i]] == 0 || mp[s[i]] == t[i])
                mp[s[i]] = t[i];
            else return false;
        }
        mp = {};
        for(int i=0;i<s.size();i++)
        {
            if(mp[t[i]] == 0 || mp[t[i]] == s[i])
                mp[t[i]] = s[i];
            else return false;
        }
        return true;
    }
};

int main()
{
    
}
