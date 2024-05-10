#include <iostream>

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        map<float ,pair<int , int> > mp;
        vector<float>ans;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                float temp = (double)arr[i] / (double)arr[j];
                ans.push_back(temp);
                mp[temp] = {arr[i] , arr[j]};
            }
        }

        sort(ans.begin() , ans.end());
        auto [first , second] = mp[ans[k-1]];
        
        vector<int> res;
        res = {first , second};
        return res;
    }
};

int main()
{
    double a = 10.2;
    

    return 0;
}
