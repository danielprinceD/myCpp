#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i=0 , n=intervals.size();
        int st = newInterval[0] , end = newInterval[1];
        while(i<n && intervals[i][1] < st)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        vector<int> merger = {st , end};
        while(i < n && intervals[i][0] <= end)
        {
            merger[0] = min(merger[0] , intervals[i][0]);
            merger[1] = max(merger[1] , intervals[i][1]);
            i++;
        }
        ans.push_back(merger);
        while(i < n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v={
        {1,2},{3,5},{6,7},{8,10},{12,16}
    };
    vector<int> in = {4 , 8};
    vector<vector<int>> newV = s.insert(v , in);
    for(auto i : newV)
    {
        for(auto j : i)
        cout<<j<<" ";
        cout<<endl;
    }
    
}
