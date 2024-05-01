#include <iostream>

class Solution {
    public:
    Node* deleteK(Node *head,int K){
        if(!head || K <= 1) return nullptr;
        Node* prev = NULL , *ptr = head; int count = 1;
        while(ptr != NULL)
        {
            if(count % K == 0) 
            {
                prev->next = ptr->next;
                ptr->next = NULL;
                ptr = prev->next;
            }else 
            {
            prev = ptr;
            ptr = ptr->next;
            }
            count++;
        }
        return head;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
