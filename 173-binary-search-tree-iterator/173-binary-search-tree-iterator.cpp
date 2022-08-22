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
class BSTIterator {
public:
    stack<TreeNode*> s;
    TreeNode* curr=NULL;
    BSTIterator(TreeNode* root) {
        curr=root;
        
    }
    
    int next() {
        while(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        TreeNode* t=s.top();
        s.pop();
        curr=t->right;
        return t->val;
    }
    
    bool hasNext() {
        return (curr!=NULL || !s.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */