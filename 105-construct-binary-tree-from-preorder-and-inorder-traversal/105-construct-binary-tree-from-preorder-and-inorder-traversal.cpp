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
    int findpos(vector<int> inorder,int element){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* tree(vector<int> preorder,vector<int> inorder,int inStart,int inEnd,int &preindex,int n){
        if(preindex>=n || inStart>inEnd){
            return NULL;
        }
        int element=preorder[preindex++];
        TreeNode* root=new TreeNode(element);
        int pos=findpos(inorder,element);
        root->left=tree(preorder,inorder,inStart,pos-1,preindex,n);
        root->right=tree(preorder,inorder,pos+1,inEnd,preindex,n);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex=0;
        int n=inorder.size();
        return tree(preorder,inorder,0,n-1,preindex,n);
    }
};

