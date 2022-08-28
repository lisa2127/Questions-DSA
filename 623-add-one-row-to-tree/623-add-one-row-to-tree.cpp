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
    void solve(TreeNode* root,int val,int depth,int d){
        if(root==NULL){
            return;
        }
        if(d<=depth-2){
            solve(root->left,val,depth,d+1);
            solve(root->right,val,depth,d+1);
        }
        else{
            TreeNode* temp=root;
            TreeNode* a=new TreeNode(val);
            a->left=temp->left;
            TreeNode* b=new TreeNode(val);
            b->right=temp->right;
            temp->left=a;
            temp->right=b;
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        solve(root,val,depth,1);
        return root;
    }
};