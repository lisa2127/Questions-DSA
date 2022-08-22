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
    /*void inorder(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return 0;
        }
        vector<int> ans;
        inorder(root,ans);
        return ans[k-1];
    }*/
    void kth(TreeNode* root,int &cnt,int k,int &ans){
         if(root==NULL){
            return;
        }
        kth(root->left,cnt,k,ans);
        cnt++;
        if(cnt==k){
            ans=root->val;
        }
        kth(root->right,cnt,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && k==1){
            return root->val;
        }
        int ans=0;
        int cnt=0;
        kth(root,cnt,k,ans);
        return ans;
    }
};