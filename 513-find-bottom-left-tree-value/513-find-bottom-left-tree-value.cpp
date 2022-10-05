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
    void lview(TreeNode* root,vector<int> &ans,int l){
        if(root==NULL){
            return;
        }
        if(ans.size()==l){
            ans.push_back(root->val);
        }
        lview(root->left,ans,l+1);
        lview(root->right,ans,l+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        vector<int> temp;
        lview(root,temp,0);
        return temp[temp.size()-1];
    }
};