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
     vector<int> find(int value,vector<int> &v,int mini,int maxi,int n)
    {
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(v[mid]==value)
            {
                return {value,value};
            }
            else if(v[mid]<value)
            {
                maxi=max(maxi,v[mid]);
                low=mid+1;
            }
            else
            {
                mini=min(mini,v[mid]);
                high=mid-1;
            }
        }
        if(mini==INT_MAX) mini=-1;
        if(maxi==INT_MIN) maxi=-1;
        return {maxi,mini};
    }
    void inorder(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        vector<vector<int>> res;
        vector<int> ans;
        inorder(root,ans);
        int n=ans.size();
        for(int i=0;i<q.size();i++){
            int mini=INT_MAX,maxi=INT_MIN;
            auto p = find(q[i],ans,mini,maxi,n);
            res.push_back(p);
        }
        return res;
    }
};