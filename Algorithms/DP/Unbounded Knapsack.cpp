#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<int> prev(w+1, 0);

    for(int target=0;target<=w;target++)
        if(target % weight[0] == 0)
            prev[target] = profit[0] * (target / weight[0]);
        else 
            prev[target] = -1e9;
    
    for(int i=1;i<n;i++)
    {
        vector<int> cur(w+1 , 0);
        for(int target=0;target<=w;target++)
        {
            int notTake = prev[target];
            int take = -1e9;
            if(weight[i] <= target)
                take = profit[i] + cur[target - weight[i]];
            cur[target] = max(take , notTake);
        }
        prev = cur;
    }

    int ans = prev[w];
    return (ans <= -1e9) ? 0 : ans;
}


int main()
{
    vector<int> profit = {5, 11, 13};
    vector<int> weight = {2, 4, 6};
    cout<<unboundedKnapsack(profit.size(), 10 , profit , weight);
    return 0;
}