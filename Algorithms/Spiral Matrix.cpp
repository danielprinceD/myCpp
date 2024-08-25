#include <iostream>

vector<int> spiralMatrix(vector<vector<int>>&arr) {
    vector<int> ds;
    int n = arr.size() , m = arr[0].size();

    int top = 0 , bottom = n-1;
    int left = 0 , right = m-1;

    while(left <= right && top <= bottom)
    {

        for(int i=left;i <= right;i++)
            ds.push_back(arr[top][i]);
        top++;

        for(int i=top;i<=bottom;i++)
            ds.push_back(arr[i][right]);
        
        right--;
        
        if(top <= bottom)
        {
            for(int i=right;i>=left;i--)
                ds.push_back(arr[bottom][i]);
            bottom--;
        }

        if(left <= right)
        {
            for(int i=bottom;i>=top;i--)
                ds.push_back(arr[i][left]);
            left++;
        }
    }

    return ds;
}

int main()
{
    std::cout<<"Hello World";

    return 0;
}