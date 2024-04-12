#include <iostream>

class Solution {
  public:
    long long pairAndSum( int n, long long arr[] ){
        long long sum = 0;
        for(int i=0;i<32;i++)
        {
            int k = 0;
            for(int j=0;j<n;j++)
                if(arr[j] & (1 << i ))
                    k++;
            sum += (1 << i) * (k * (k-1))/2; 
        }
        return sum;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
