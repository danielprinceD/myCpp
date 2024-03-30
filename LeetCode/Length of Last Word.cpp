#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size()-1;
        while( n >= 0 && s[n] == ' ')
            n--;
        string temp="";
        while( n >= 0 && s[n]!=' ')
        {
            temp+=s[n];
            n--;
        }
        return temp.size();
    }
};

int main()
{
    Solution s;
    
}
