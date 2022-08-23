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
    int solve(TreeNode* root,int &sum){
        if(root==NULL){
            return 0;
        }
        int r=solve(root->right,sum);
        sum=root->val+sum;
        root->val=sum;
        int l=solve(root->left,sum);
        return sum;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        int sum=0;
        solve(root,sum);
        return root;
    }
};