class Node{
    public:
    string data;
    Node* next;
    Node* prev;
    Node(string data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
class BrowserHistory {
public:
    Node* curr=NULL;
    BrowserHistory(string homepage) {
        curr=new Node(homepage);
    }
    
    void visit(string url) {
        Node* temp=new Node(url);
        curr->next=temp;
        temp->prev=curr;
        curr=curr->next;
    }
    
    string back(int steps) {
        while(curr->prev!=NULL && steps>0){
            curr=curr->prev;
            steps--;
        }
        return curr->data;
    }
    
    string forward(int steps) {
         while(curr->next!=NULL && steps>0){
            curr=curr->next;
            steps--;
        }
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */