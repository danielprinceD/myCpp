#include <iostream>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int i=0 , j = 0, n = sandwiches.size();
        int size = students.size() , iter = 0;
        while(j < n && iter < size - j)
        {
            if(students[i] == sandwiches[j])
            {
                i++;j++;iter = 0;
            }
            else 
            {
                students.push_back(students[i]);
                i++;
                iter++;
            }
        }
        return n - j;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
