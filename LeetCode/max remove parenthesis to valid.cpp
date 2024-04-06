#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> badIndex(s.size() , 0);
        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')')
                if(st.empty())badIndex[i] = 1;
                else st.pop();
        }

        while(!st.empty())
        {
            badIndex[st.top()] = 1;
            st.pop();
        }
        string temp = "";
        for(int i=0;i<s.size();i++)
        {
            if(badIndex[i] == 0)
                temp+=s[i];
        }
        return temp;

    }
};

int main()
{
    Solution s;
    cout<<s.minRemoveToMakeValid("l(e)e)t(co)de)");
}
