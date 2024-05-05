#include <iostream>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin() , people.end());
        int i = 0 , j = people.size()-1;
        int count = 0;
        while(i <= j)
        {
            if(people[i] + people[j] > limit)
            {
                j--;
            }
            else
            {
                i++; j--;
            }
            count++;
        }
        return count;
    }
};

int main()
{
}
