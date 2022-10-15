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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2,-1);
        ListNode* prev=head;
        ListNode* forward=NULL;
        ListNode* curr=head->next;
        int mini=INT_MAX;
        int pos=1;
        vector<int> critic;
        while(curr!=NULL && curr->next!=NULL){
            forward=curr->next;
            pos++;
            if((curr->val <forward->val && curr->val <prev->val) || (curr->val > forward->val && 
                                                                    curr->val > prev->val)){
                critic.push_back(pos);
            }
            prev=curr;
            curr=curr->next;
        }
        if(critic.size()==0 || critic.size()==1){
            return ans;
        }
        //cout<<critic.size();
        for(int i=1;i<critic.size();i++){
            mini=min(mini,critic[i]-critic[i-1]);
        }
        ans[0]=mini;
        ans[1]=critic[critic.size()-1]-critic[0];
        return ans;
    }
};