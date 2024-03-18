#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        auto cmp = [](vector<int>a , vector<int>b)
        {
          return a[1] < b[1];
        };
        sort(points.begin() , points.end() , cmp);
        
        int shoot = points[0][1] , count = 1;
        for(auto point : points )
        {
            if(shoot >= point[0])continue;
            count++;
            shoot = point[1];
        }
        return count;
    }
};

int main()
{
    vector<vector<int>> v{
      {10,16},{2,8},{1,6},{7,12}  
    };
    Solution s;
    cout<<s.findMinArrowShots(v);
}
