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
    string ans="~";
    void solve(TreeNode* root,string s){
      if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ans=min(ans,char(root->val+'a')+s);
        }
        solve(root->left,char(root->val+'a')+s);
        solve(root->right,char(root->val+'a')+s);
    }
    string smallestFromLeaf(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        solve(root,"");
        return ans;
    }
};