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
    unordered_map<long,long> mp;
    long sum=0;
    int cnt=0;
    void solve(TreeNode* root,int target,long sum){
        if(root==NULL){
            return;
        }
        sum+=root->val;
        if(sum==target){
            cnt++;
        }
        if(mp.find(sum-target)!=mp.end()){
            cnt+=mp[sum-target];
        }
        mp[sum]++;
        solve(root->left,target,sum);
        solve(root->right,target,sum);
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        solve(root,targetSum,0);
        return cnt;
    }
};