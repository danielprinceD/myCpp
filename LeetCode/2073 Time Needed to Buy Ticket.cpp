#include <iostream>

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i=0 , n = tickets.size() , count = 0;
        while(tickets[k] != 0)
        {
            if(tickets[i%n] !=0)
            {
            tickets[i%n]-=1;
            count++;
            }
            i++; 
        }
        return count;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
