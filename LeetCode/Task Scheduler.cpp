#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int wait = 0;
        map<char, int> mp;
        for(auto &i : tasks)
            mp[i]++;
        priority_queue<int> pq;
        for(auto p : mp) pq.push(p.second);
        int result = 0;
        while(!pq.empty())
        {
            int time1 = 0;
           vector<int> temp;
           for(int i=0;i<n+1;i++)
           {
               if(!pq.empty())
               {
                   temp.push_back(pq.top()-1);
                   pq.pop();
                   time1++;
               }
           }
           for(auto t : temp)
           {
               if(t)
               pq.push(t);
           }
               result+= (pq.empty()) ? time1 : n+1;
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<char> v{'A' , 'A' ,'A' , 'B' , 'B' ,'B' };
    
    cout<<s.leastInterval(v , 2);
}
