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
    int tree(TreeNode* root,int &sum){
        if(root==NULL){
            return 0;
        }
        int l=tree(root->left,sum);
        int r=tree(root->right,sum);
        int ele=root->val;
        root->val=abs(l-r);
        sum+=root->val;
        return ele+l+r;
    }
   
    int findTilt(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int sum=0;
        tree(root,sum);
        return sum;
    }
};