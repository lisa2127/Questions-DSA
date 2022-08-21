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
    void createmap(vector<int> inorder,unordered_map<int,int> &mp){
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
    }
    TreeNode* tree(vector<int>& in, vector<int>& post,unordered_map<int,int> &mp,int &index,int instart,int inend){
        if(instart>inend || index<0){
            return NULL;
        }
        int element=post[index--];
        int pos=mp[element];
        TreeNode* root=new TreeNode(element);
        root->right=tree(in,post,mp,index,pos+1,inend);
        root->left=tree(in,post,mp,index,instart,pos-1);
        
        return root;
        
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        createmap(inorder,mp);
        int n=inorder.size();
        int index=n-1;
   
        return tree(inorder,postorder,mp,index,0,n-1);
        
    }
};