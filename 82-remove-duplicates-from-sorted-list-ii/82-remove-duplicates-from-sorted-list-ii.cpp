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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        map<int,int> mp;
        ListNode* curr=head;
        while(curr!=NULL){
            mp[curr->val]++;
            curr=curr->next;
        }
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        for(auto i: mp){
            if(i.second==1){
                temp->next=new ListNode(i.first);
                temp=temp->next;
            }
        }
        return ans->next;
    }
};