#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int mini = m;
        int min_ind = 1;
        for(int i=0;i<a.size();i++)
        {
            int count = 0;
            for(int j=0;j<a[0].size();j++)
                if(a[i][j]==1)count++;
            if(count < mini ){
                mini  = count ; min_ind = i+1;
            }
        }
        return min_ind;
    }
};


int main()
{
}
