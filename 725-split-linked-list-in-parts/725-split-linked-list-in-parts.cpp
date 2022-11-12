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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        ListNode* curr=head;
        int totalLen=0;
        while(curr!=NULL){
            totalLen++;
            curr=curr->next;
        }
        int len=totalLen/k;
        int vary=totalLen%k;
        ListNode* prev=NULL;
        curr=head;
        int i=0;
        while(curr!=NULL && i<k){
            ans[i]=curr;
            for(int j=0;j<len+(vary>0?1:0);j++){
                prev=curr;
                curr=curr->next;
            }
            prev->next=NULL;
            i++;
            vary--;
        }
        return ans;
    }
};