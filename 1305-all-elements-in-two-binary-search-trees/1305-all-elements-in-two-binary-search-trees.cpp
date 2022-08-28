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
    void inorder(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        inorder(root1,a);
        inorder(root2,b);
        vector<int> sol(a.size()+b.size());
        int i=0;
        int j=0;
        int k=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]){
                sol[k++]=a[i++];
            }
            else{
                sol[k++]=b[j++];
            }
        }
        while(i<a.size()){
            sol[k++]=a[i++];
        }
        while(j<b.size()){
            sol[k++]=b[j++];
        }
        return sol;
    }
};