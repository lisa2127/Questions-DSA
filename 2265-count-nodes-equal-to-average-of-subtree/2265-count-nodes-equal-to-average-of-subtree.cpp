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
    pair<int,int> solve(TreeNode* root,int &ans){
        if(root==NULL){
            return make_pair(0,0);
        }
        pair<int,int> l=solve(root->left,ans);
        pair<int,int> r=solve(root->right,ans);
        int size=0;
        size=max(size,l.second+r.second+1);
        int avg=(l.first+r.first+root->val)/size;
        if(root->val==avg){
            ans++;
        }
        pair<int,int> temp;
        temp.first=root->val+l.first+r.first;
        temp.second=size;
        return temp;
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=0;
        solve(root,ans);
        return ans;
    }
};