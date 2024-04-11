#include <iostream>

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> q;
        for(auto c : num)
        {
            while(!q.empty() && c < q.top() && k > 0)
            {
                q.pop();
                k--;
            }
            q.push(c);
        }
        while(k > 0)
        {
            q.pop();
            k--;
        }
        string ans = "";
        while(!q.empty())
        {
            ans += q.top();
            q.pop(); 
        }
        int endInd = 0;
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(ans[i]!='0')
            {   
                endInd = i;
                break;
            }
        }
        ans = ans.substr(0 , endInd + 1);
        reverse(ans.begin() , ans.end());

        if(ans == "")ans= "0";
        return ans;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
