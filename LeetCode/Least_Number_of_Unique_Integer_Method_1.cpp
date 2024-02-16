#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int , int> map;
        for(int i : arr)map[i]++;
        
        vector<int> freq;
        for(auto i : map)freq.push_back(i.second);
        sort(freq.begin(),freq.end());
        
        int removed=0;
        for(int i=0;i<freq.size();i++)
        {
            removed+=freq[i];
            if(removed > k) return freq.size() - i;
        }
        return 0;
    }
};
int main()
{
    Solution s;
    vector<int> v{4,3,1,1,3,3,2};
    cout<<s.findLeastNumOfUniqueInts(v,3);
}
