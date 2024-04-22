#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char leftTurn(char ch)
    {
        return (ch == '0' ? '9' : ch-1);
    }
    char rightTurn(char ch)
    {
        return (ch == '9' ? '0' : ch+1);
    }
    vector<string> nextOption(string s)
    {
        vector<string> ans;
        for(int i=0;i<4;i++)
        {
            string copy = s;
            copy[i] = leftTurn(s[i]);
            ans.push_back(copy);
            copy[i] = rightTurn(s[i]);
            ans.push_back(copy);
        }
        return ans;
    }
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_map<string , bool> vis;
        q.push("0000");
        vis["0000"] = 1;
        int level = 0;
        for(auto d : deadends)if(d != "0000")vis[d] = 1; else return -1;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string s = q.front();
                if(s==target)return level;
                q.pop();
                for(auto i : nextOption(s))
                {
                    if(!vis[i])
                    {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<string> dead = {"0201","0101","0102","1212","2002"};
    cout<<s.openLock(dead , "0202");
}
