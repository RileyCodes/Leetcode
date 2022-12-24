class MyStack {
public:
    
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        for(int i =0 ; i < q.size() - 1; ++i)
        {
            int data = q.front();
            q.pop();
            q.push(data);
        }
        int data = q.front();
        q.pop();
        return data;
    }
    
    int top() {
        for(int i =0 ; i < q.size() - 1; ++i)
        {
            int data = q.front();
            q.pop();
            q.push(data);
        }
        
        //1 2
        //3 1 2
        //2 3 1
        //1 2 3
        int data = q.front();
        q.pop();
        q.push(data);
        return data;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */