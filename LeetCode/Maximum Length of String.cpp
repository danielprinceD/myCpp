#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int i=0 , j = s.size()-1;
        while(i<j && s[i]==s[j])
        {
            char str = s[i];
            while(s[i] == str && i < j)i++;        
            while(s[j]==str && i <= j)j--;
        }
        return j-i+1;
    }
};

int main()
{
    Solution s;
    cout<<s.minimumLength("cabaabac");
}
