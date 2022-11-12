/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //step-1
        Node* curr=head;
        while(curr){
            Node* temp=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=temp;
            curr=temp;
        }
        //step-2
        curr=head;
        while(curr){
            if(curr->random){
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        //step-3
        Node* ans=new Node(0);
        Node* help=ans;
        while(head){
            help->next=head->next;
            help=help->next;
            head->next=head->next->next;
            head=head->next;
        }
        return ans->next;
    }
};
