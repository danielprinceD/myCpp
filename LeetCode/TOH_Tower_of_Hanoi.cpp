#include <iostream>

using namespace std;

int TOH(int n,char start,char use,char end)
{
    if(n>0)
    {
        if(n==1)
        {
            cout<<start<<" -> "<<end<<endl;
        }
        else
        {
        TOH(n-1,start,end,use);
        cout<<start<<" -> "<<end<<endl;
        TOH(n-1,use,start,end);
        }
    }
    return 0;
}

int main()
{
    
    TOH(3,'A','B','C');
    return 0;
}
