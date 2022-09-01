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
    void createmap(vector<int> in,unordered_map<int,int> &mp){
        for(int i=0;i<in.size();i++){
            mp[in[i]]=i;
        }
    }
    TreeNode* maketree(vector<int> pre,vector<int> in,int instart,int inend,int &preindex,
                      unordered_map<int,int> &mp){
        if(instart>inend || preindex>in.size()){
            return NULL;
        }
        int index=mp[pre[preindex++]];
        TreeNode* root=new TreeNode(in[index]);
        root->left=maketree(pre,in,instart,index-1,preindex,mp);
        root->right=maketree(pre,in,index+1,inend,preindex,mp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> temp=preorder;
        vector<int> in;
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            in.push_back(temp[i]);
        }
        unordered_map<int,int> mp;
        createmap(in,mp);
        int n=preorder.size();
        int i=0;
        return maketree(preorder,in,0,n-1,i,mp);
    }
};