class Solution {
public:
    /*
    这道题我们首先根据区间起点对区间进行排序。
    知识点：sort对vector<vector<int>> 排序时，自动会使用第一个元素为排序的依据。
    sort(intervals.begin(),intervals.end());
    
    排序以后，我们可以肯定区间 i 的起点必然 <= 区间 i - 1，因为我们已经根据起点排序过了，只会越来越大。
    因此，迭代的时候遇到的每个区间只可能相等或者在更右边。
    
    不难想到，因为这个原因，对于区间 i + 1，我们只需要判断其起点是否比0到i的区间中，最小的终点大就可以了。
    
    比如说
    [1,5]
    [1,10]

    我们现在在处理[2,3]

    从0到1的区间最小终点是5，我们的区间数据是[5,10]
     如果我们手里有一个[6,?]开头的区间，就能不需要新的分组
    对于[2,3]，因为2 > 最小右侧区间5，所以需要开辟一个新的分组
    然后全局最小右侧区间变成了3，我们的区间数据是[3,5,10]
    然后处理[5,10]，可以放在3后面，所以分组变成了
    [1,5]
    [1,10]
    [2,3],[5,10]
    全局最小右侧区间变成了5，我们的区间数据是[5,5,10]

    [6,8]可以放在5右边，所以我们得到了
    [1,5],[6,8]
    [1,10]
    [2,3],[5,10]
    我们的区间数据是[6,5,10]

    最后发现只要3个分组就可以了。

    由此可见，空间复杂度是分组的数量n，获取最小的右侧区间，删除最小的右侧区间和插入新的右侧区间可以用最小堆实现，时间复杂度是log(n)
    
    在C++中，可以直接使用基于STL的priority_queue<int,vector<int>,greater<int>> p;
    
    对每个区间做一次log(n)的操作，我们的时间复杂度是nlog(n)，排序的时间复杂度也是nlog(n)。 所以最终复杂度就是nlog(n)
    知识点：priority_queue默认是最大堆，利用比较器greater<int>可以改为最小堆，比较器greater<int>也可以在sort中使用，使其降序排序。
    */
    int minGroups(vector<vector<int>>& intervals) {
        int m = 0;
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>> p;
                
        for(int i = 0;i < intervals.size();++i)
        {
            if(!p.empty() && p.top() < intervals[i][0])
            {
                p.pop();
                p.push(intervals[i][1]);
            }
            else
            {
                ++m;
                p.push(intervals[i][1]);
            }
            //cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]" << endl;
        }
        return m;
    }
};