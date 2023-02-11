class Solution {
public:


    void insert(vector<pair<int,int>>& heap, int& count,pair<int,int> value)
    {
        heap[++count] = value;
        int i = count;
        while(i / 2 > 0)
        {
            if(heap[i / 2].second < heap[i].second)
            {
                swap(heap[i / 2], heap[i]);
                i = i / 2;
            }
            else
                break;
        }
    }
    

    int getMax(vector<pair<int,int>>& heap, int& count)
    {
        int result = heap[1].first;
        heap[1] = heap[count--];
        int i = 1;
        while(i * 2 <= count)
        {
            int j = i * 2;
            if(j + 1 <= count && heap[j + 1].second > heap[j].second)
                ++j;
            if(heap[j].second > heap[i].second)
                swap(heap[j], heap[i]);
            else
                break;

            i = j;
        }
        return result;
    }


    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for(auto&& num : nums)
            ++counter[num];

        int count = 0;
        vector<pair<int,int>> heap(counter.size() + 1);

        for(auto&& kv : counter)
            insert(heap, count, kv);
        vector<int> ans;
        for(int i = 0; i < k ; ++i)
            ans.emplace_back(getMax(heap, count));
        return ans;
    }
};