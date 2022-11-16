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
    void createmap(vector<int> arr,unordered_map<int,int> &mp){
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]=i;
    }
}
TreeNode* solve(vector<int> ino,vector<int> pre,unordered_map<int,int> &mp,int instart,int inend,int &i,int n){
    if(instart>inend || i>=n){
        return NULL;
    }
    int ele=pre[i++];
    int pos=mp[ele];
    TreeNode* root=new TreeNode(ele);
    root->left=solve(ino,pre,mp,instart,pos-1,i,n);
    root->right=solve(ino,pre,mp,pos+1,inend,i,n);
    return root;
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> mp;
    createmap(inorder,mp);
    int n=inorder.size();
    int i=0;
    return solve(inorder,preorder,mp,0,n-1,i,n);
    }
};

