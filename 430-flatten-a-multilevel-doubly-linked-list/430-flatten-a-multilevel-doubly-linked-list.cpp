/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr=head,*temp,*runner;
        while(curr!=NULL){
            if(curr->child){
                temp=curr->next;
                curr->next=curr->child;
                curr->next->prev=curr;
                curr->child=NULL;
                
                runner=curr->next;
                while(runner->next!=NULL){
                    runner=runner->next;
                }
                runner->next=temp;
                if(runner->next){
                    runner->next->prev=runner;
                }
                
            }
            curr=curr->next;
        }
        return head;
    }
};