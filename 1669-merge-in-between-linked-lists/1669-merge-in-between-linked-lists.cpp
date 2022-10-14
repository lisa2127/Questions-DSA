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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr=list1;
        ListNode* temp=list2;
        ListNode* prev=NULL;
        ListNode* upcom=NULL;
        int cnt=0;
        while(curr!=NULL && cnt<a){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        while(curr!=NULL && cnt<b){
            curr=curr->next;
            cnt++;
        }
        upcom=curr->next;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=upcom;
        prev->next=list2;
        return list1;
    }
};