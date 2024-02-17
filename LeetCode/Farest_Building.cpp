#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int,vector<int> , greater<int>> pq;
        for(int i=0;i<h.size()-1;i++)
        {
            int gap = h[i+1] - h[i];
            if(gap > 0)pq.push(gap);
            if(pq.size() > l)
            {
                b -= pq.top();pq.pop();
            }
            if(b < 0)return i;
        }
        return h.size() -1;
    }
    
};
int main()
{
    Solution s;
    vector<int> v = {4,12,2,7,3,18,20,3,19};
    cout<<s.furthestBuilding(v,10,2);
}
