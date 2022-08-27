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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int maxwidth=0;
        while(!q.empty()){
            int size=q.size();
            int max_index=INT_MIN;
            int min_index=INT_MAX;
            for(int i=0;i<size;i++){
               
                TreeNode* temp=q.front().first;
                int dist=q.front().second;
                q.pop();
                max_index=max(max_index,dist);
                min_index=min(min_index,dist);
                if(temp->left){
                    q.push({temp->left,(long long)2*dist+1});
                }
                if(temp->right){
                    q.push({temp->right,(long long)2*dist+2});
                }
                
            }
            maxwidth=max(maxwidth,max_index-min_index+1);
        }
        return maxwidth;
    }
};