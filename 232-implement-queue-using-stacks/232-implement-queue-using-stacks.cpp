class MyQueue {
    stack<int> s;
public:
    MyQueue() {
        
    }
    
    void enqueue(stack<int> &s,int x){
        if(s.size()==0){
            s.push(x);
            return;
        }
        int ele=s.top();
        s.pop();
        enqueue(s,x);
        s.push(ele);
    }
    void push(int x) {
        
        enqueue(s,x);
    }
    
    int pop() {
        if(s.size()==0){
            return -1;
        }
        int p=s.top();
        s.pop();
        return p;
    }
    
    int peek() {
        if(s.size()==0){
            return -1;
        }
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */