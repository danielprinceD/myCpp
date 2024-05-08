#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        map<int , string> mp;
        set<int , greater<int > > s(score.begin() , score.end() ); 
        int place = 1;
        for(auto i : s)
        {
            if(place==1) mp[i] = "Gold Medal";
            else if( place == 2) mp[i] = "Silver Medal";
            else if(place ==3) mp[i] = "Bronze Medal";
            else mp[i] = to_string(place);
            place++;
        }   
        for(auto i : score)
            ans.push_back(mp[i]);
        return ans;
    }
};

int main()
{
}
