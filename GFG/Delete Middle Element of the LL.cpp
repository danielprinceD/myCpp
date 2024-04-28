#include <iostream>
using namespace std;

class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        if(head==NULL || head->next == NULL)return NULL;
        Node* fast = head; Node * slow = head , *prev = NULL;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        prev->next = slow->next;
        return head;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}