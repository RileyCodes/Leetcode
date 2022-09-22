class MovingAverage {
public:
    
    queue<int> q;
    int size = 0;
    int sum = 0;
    
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        q.push(val);
        
        if(q.size() > size)
        {
            sum -= q.front();
            q.pop();
        }

        sum += val;
        
        return (double)sum / (double)q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */