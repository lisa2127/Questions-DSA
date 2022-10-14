class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class MyHashSet {
public:
    Node* head=NULL;
    MyHashSet() { 
        head=new Node(-1);
    }
    
    void add(int key) {
        Node* temp=new Node(key);
        Node* curr=head;
        while(curr->next!=NULL){
            if(curr->next->data==key){
                return;
            }
            curr=curr->next;
        }
        curr->next=temp;
        return;
    }
    
    
    void remove(int key) {
        if(head->next==NULL){
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            if(temp->next->data==key){
                temp->next=temp->next->next;
                return;
            }
            temp=temp->next;
        }
    }
    
    bool contains(int key) {
        if(head->next==NULL){
            return false;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            if(temp->next->data==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */