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
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev=NULL;
    void correctBST(TreeNode* root){
        if(root==NULL){
            return;
        }
        correctBST(root->left);
        // we are following inorder fashion LNR writing the dip condition
        if(prev!=NULL && prev->val > root->val){
            if(first==NULL){
                first=prev;
            }
            second=root;
        }
        prev=root;
        correctBST(root->right);
    }
    void recoverTree(TreeNode* root) {
        correctBST(root);
        swap(first->val,second->val);
    }
};