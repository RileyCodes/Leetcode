class MedianFinder {
public:

    static constexpr auto compare = [](auto&a, auto&b){return a > b;};
    priority_queue<int, vector<int>,decltype(compare)> min_q;
    priority_queue<int, vector<int>> max_q;
    
    MedianFinder() : min_q(compare) {}
    
    void addNum(int num) {
        if(min_q.size() >= max_q.size())
        {
            min_q.push(num);
            max_q.push(min_q.top());
            min_q.pop();
        }
        else
        {
            max_q.push(num);
            min_q.push(max_q.top());
            max_q.pop();
        }
    }
    
    double findMedian() {
        if(min_q.size() > max_q.size())
            return min_q.top();
        else if(min_q.size() < max_q.size())
            return max_q.top();
        else 
            return (double)(min_q.top() + max_q.top()) / 2.0;
        return -1.0f;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */