#include <iostream>

class Solution{
public:
    vector<vector<int>> ans;
    void solver(int ind , int sum , vector<int > &arr , vector<int> &temp)
    {
        if(sum==0)
        {
            ans.push_back(temp); return;
        }
        for(int i=ind;i<arr.size();i++)
        {
            if(ind < i && arr[i] == arr[i-1])continue;
            if(arr[i] > sum) break;
            temp.push_back(arr[i]);
            solver(i+1 , sum-arr[i] , arr , temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        sort(arr.begin() ,arr.end());
        vector<int> temp;
        solver(0 , k , arr , temp);
        return ans;
    }
};


int main()
{
    double a = 10.2;
    

    return 0;
}
