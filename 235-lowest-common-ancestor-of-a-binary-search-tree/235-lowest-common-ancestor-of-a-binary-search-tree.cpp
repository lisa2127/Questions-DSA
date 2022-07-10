/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
        if(root==NULL){
            return NULL;
        }
        
        if(root->val < a->val && root->val <b->val ){
            return lowestCommonAncestor(root->right,a,b);
        }
        if(root->val > a->val && root->val >b->val){
            return lowestCommonAncestor(root->left,a,b);
        }
        if((root->val <=a->val && root->val >=b->val)||(root->val >= a->val && root->val <=b->val)){
            return root;
        }
        return NULL;
    }
};