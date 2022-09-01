/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*bool isCrt(vector<int> temp,int k){
        for(int i=0;i<temp.size();i++){
            if(temp[i]>k){
                return false;
            }
        }
        return true;
    }
    void solve(TreeNode* root,vector<int> temp,int &cnt){
        if(root==NULL){
            return;
        }
        temp.push_back(root->val);
        solve(root->left,temp,cnt);
        solve(root->right,temp,cnt);
        if(isCrt(temp,root->val)){
            cnt++;
        }
        temp.pop_back();
        
    }*/
    
        void solve(TreeNode* root,int curr,int &cnt){
        if(root==NULL){
            return;
        }
        if(root->val >= curr){
            cnt++;

        }
        solve(root->left,max(curr,root->val),cnt);
        solve(root->right,max(curr,root->val),cnt);
            
    }

    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int cnt=0;
        //vector<int> ans;
        solve(root,INT_MIN,cnt);
        return cnt;
    }
};