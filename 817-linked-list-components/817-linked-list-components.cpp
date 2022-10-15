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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int cnt=0;
        int comp=0;
        ListNode* temp=head;
        while(temp!=NULL){
            int d=temp->val;
            if(mp.find(d)!=mp.end()){
                cnt++;
            }
            else{
                if(cnt>0){
                    comp++;
                }
                cnt=0;
            }
            temp=temp->next;
            
        }
        if(cnt>0){
            comp++;
        }
        return comp;
    }
};