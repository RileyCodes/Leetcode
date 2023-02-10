class SeatManager {
    vector<int> heap;
    int count;
public:

    SeatManager(int n) : count(n)
    {
        for(int i = 0; i <= n; ++i)
            heap.emplace_back(i);

    }


    int reserve() {
        int result = heap[1];
        heap[1] = heap[count--];
        int i = 1;
        while(i * 2 <= count)
        {
            int j = i * 2;
            if(j + 1 <= count && heap[j + 1] < heap[j])
                ++j;
            if(heap[i] < heap[j])
                break;
            swap(heap[i],heap[j]);
            i = j;
        }
    
        return result;
    }
    
    void unreserve(int seatNumber) {
        heap[++count] = seatNumber;
        int i = count;
        while(i / 2 > 0 && heap[i] < heap[i / 2])
        {
            swap(heap[i], heap[i / 2]);
            i = i / 2;
        }       
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */