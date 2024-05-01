#include <iostream>
using namespace std;

class Solution {
  public:
    struct Node* arrangeCV(Node* head) {
        Node* ptr = head , *vow = NULL , *cons = NULL , *vtail=NULL , *ctail = NULL;
        while(ptr)
        {
            int ch = ptr->data;
            Node* temp = new Node(ch);
            if(ch == 'a' || ch== 'e' || ch== 'i' || ch== 'o' || ch== 'u')
            {
                    
                if(vow==NULL)
                {
                    vow = new Node(ch);
                    vtail = vow;
                }
                else 
                {
                    vtail->next = temp;
                    vtail = temp;
                }
            }
            else{
                
                if(cons==NULL)
                {
                    cons = new Node(ch);
                    ctail = cons;
                }
                else 
                {
                    ctail->next = temp;
                    ctail = temp;
                }
            }
            ptr = ptr->next;
        }
        if(vow == NULL)return cons;
        if(cons == NULL)return vow;
        vtail->next = cons;
        return vow;
    }
};

int main()
{
    return 0;
}
