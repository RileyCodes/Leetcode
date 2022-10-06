class ProductOfNumbers {
public:
    vector<vector<int>> prefix_sum;
    vector<int>* cur_prefix = nullptr;
        
    ProductOfNumbers() {
        prefix_sum.emplace_back(vector<int>());
        cur_prefix = &prefix_sum[0];
    }
    
    void add(int num) {
        if(cur_prefix->size() == 0)
            cur_prefix->emplace_back(num);
        else
            cur_prefix->emplace_back(num * (*cur_prefix)[cur_prefix->size() - 1]);
        
        if(num == 0)
        {
            prefix_sum.emplace_back(vector<int>());
            cur_prefix = &prefix_sum[prefix_sum.size() - 1];
        }
    }
    
    int getProduct(int k) {

        if(k > cur_prefix->size())
            return 0;

        int divIndex = cur_prefix->size() - 1 - k;
        if(divIndex < 0)
            return ((*cur_prefix)[cur_prefix->size() - 1]);
        
        return ((*cur_prefix)[cur_prefix->size() - 1]) / 
            ((*cur_prefix)[cur_prefix->size() - 1 - k]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */