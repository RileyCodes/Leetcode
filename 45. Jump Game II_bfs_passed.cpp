class Solution {
public:
    int jump(vector<int>& nums) {
         //这道题要求我们找出跳跃次数最小的，从数组最左边走到最右边的办法。
        //不难想到，我们上一题用的递归方法在这道题会超时，因为我们采取的实际上是DFS搜索，抓到一个元素一直递归，找到这个元素的所有路径再比较最小的。 如果我们使用BFS，那么最先找到的路径就是最短路径了。
        if(nums.size() == 1)
            return 0;
        
        queue<int> q;
        q.push(nums.size() - 1);
        q.push(-1);//层级标识符
        int depth = 0;
        vector<bool> visited(nums.size());
        
        while(!q.empty())
        {
            //k是当前队列pop出来的，需要找到可以抵达k的左侧所有元素
            int k = q.front();
            q.pop();
            
            if(k == -1)//我们并不需要担心标识符死循环的问题，因为这道题保证了一定有解。
            {
                //cout << "#";
                ++depth;
                q.push(-1);//层级标识符
                continue;
            }

            
            if(visited[k])
                continue;
            
            visited[k] = true;
            
            if(k == 0)
                return depth;            
            for(int i = k - 1; i >= 0; --i)//从k左侧从左到右搜索。
            {
                //如果当前元素的值大于等于 k和i的距离，这意味着元素 i 可以抵达 k
                if(nums[i] >= k - i)
                {
                    q.push(i);//加入可以抵达的元素到队列       
                    //cout<<" ||"<<i<<"|| ";
                }
            }   
        }
        return depth;
    }
};