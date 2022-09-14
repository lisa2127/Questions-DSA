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
  
    void path(TreeNode* root,set<int> s,int &count){
        if(s.find(root->val)!=s.end()){
            s.erase(root->val);
        }
        else{
            s.insert(root->val);
        }
        if(root->left==NULL && root->right==NULL){
            if(s.size()<=1){
                count++;
            }
            return;
        }
        if(root->left){
            path(root->left,s,count);
        }
        if(root->right){
            path(root->right,s,count);
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int count=0;
        set<int> s;
        path(root,s,count);
        return count;
    }
    
};