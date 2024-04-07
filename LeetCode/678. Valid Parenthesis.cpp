#include <iostream>

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st; stack<int>start;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '*')start.push(i);
            else if(s[i] == '(')st.push(i);
            else if(s[i] == ')')
            {
                if(!st.empty())
                    st.pop();
                else if(!start.empty()) start.pop();
                else return  false;
            }
            else return false;
        }
        while(!st.empty() && !start.empty())
        {
            if(st.top() > start.top())return false;
            st.pop();start.pop();
        }
        return st.empty();
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
