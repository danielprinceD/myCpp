#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());
        set<array<long long, 2>> sheduled;
        set<int> open;
        vector<int> used(n, 0);
        for (int i = 0; i < n; i++)
            open.insert(i);
        for (int i = 0; i < meetings.size(); i++)
        {
            while (sheduled.size() and (*sheduled.begin())[0] <= meetings[i][0])
            {
                open.insert((*sheduled.begin())[1]);
                sheduled.erase(sheduled.begin());
            }
            if (open.size() == 0)
            {
                long long diff = meetings[i][1] - meetings[i][0];
                auto u = *sheduled.begin();
                sheduled.erase(sheduled.begin());
                long long start = u[0], room = u[1];
                sheduled.insert({start + diff, room});
                used[room]++;
            }
            else
            {
                int room = *open.begin();
                open.erase(open.begin());
                sheduled.insert({meetings[i][1], room});
                used[room]++;
            }
        }

        int maxi = 0, max_i = -1;
        for (int i = 0; i < n; i++)
        {
            if (used[i] > maxi)
            {
                max_i = i;
                maxi = used[i];
            }
        }
        return max_i;
    }
};

int main()
{
    vector<vector<int>> m = {
        {1, 20},
        {2, 10},
        {3, 5},
        {4, 9},
        {6, 8},
    };
    Solution s;
    cout << s.mostBooked(3, m);
    return 0;
}
