/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<Node*> v;
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                v.push_back(temp);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            int n=v.size();
            if(n==1){
                Node* curr=v[0];
                curr->next=NULL;
            }
            else{
                for(int i=0;i<n-1;i++){
                    Node* curr=v[i];
                    curr->next=v[i+1];
                }
                Node* curr=v[n-1];
                curr->next=NULL;
            }
        }
        return root;
    }
};