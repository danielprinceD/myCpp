#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int Maxdepth = 0 ,open = 0;
        for(int i=0;i<s.size();i++)
        {
            
            if(s[i] == '(')
                open++;
            else if(s[i] == ')')
            {
                Maxdepth = max(Maxdepth , open);
                open--;
            }
        }
        return Maxdepth;
    }
};

int main()
{
    Solution s;
    cout<<s.maxDepth("(()()(daniel())");
}