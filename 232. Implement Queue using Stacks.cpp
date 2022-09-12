class MyQueue {
    
    stack<int> s;
    stack<int> s2;
public:
    
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        
        //1 2 3 4
        //pop 4 3 2
        //2 3
        
        int count = s.size() - 1;
        for(int i = 0 ;i < count; ++i)
        {
            s2.push(s.top());
            s.pop();
        }
        
        int data = s.top();
        s.pop();
        
        while(!s2.empty())
        {
            s.push(s2.top());
            s2.pop();
        }
        
        return data;
    }
    
    int peek() {
        
        int data;
        
        //1 2
        while(!s.empty())
        {
            s2.push(s.top());
            data = s.top();
            s.pop();
        }
        
        while(!s2.empty())
        {
            s.push(s2.top());
            s2.pop();
        }
        
        return data;
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