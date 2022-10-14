/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL|| headB==NULL){
            return NULL;
        }
        
        ListNode* first=headA;
        ListNode* second=headB;
        map<ListNode*,bool>visited;
        while(first!=NULL){
            visited[first]=true;
            first=first->next;
        }
        while(second!=NULL){
            if(visited[second]==true){
                return second;
            }
            second=second->next;
        }
        return 0;
    }
};