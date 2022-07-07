/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if(head==NULL){
             return head;
         }
        ListNode* pre = NULL;
        ListNode* curr = head;
        
        while(left>1){
            pre = curr;
            curr = curr->next;
            left--;
            right--;
        }
        
        ListNode* prev = NULL; 
        ListNode* forward = NULL; 
        ListNode* tail = curr; 
        
        while(right>0){             
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            right--;
        }
        
        if(pre==NULL){
            head = prev;
        }
        else{
            pre->next = prev;
        }
        
        tail->next = curr;        // connect the tail 
        
        return head;
    }
    
};