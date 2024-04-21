#include <iostream>

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        int start = 0 , end = array.size()-1;
        for(int i=0;i<=end;i=i)
        {
            int temp;
            if(array[i] < a) 
            {
                temp = array[i];
                array[i] = array[start];
                array[start] = temp;
                i++;
                start++;
            }
            else if(array[i] > b) 
            {
                temp = array[i];
                array[i] = array[end];
                array[end] = temp;
                end--;
            } else i++;
        }
    }
};


int main()
{
    std::cout<<"Hello World";

    return 0;
}