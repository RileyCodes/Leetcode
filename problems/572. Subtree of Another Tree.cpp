/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> sub_order;
    vector<int> main_order;
    
    //使用dfs创建整个子树的序列
    void dfs(TreeNode* node, vector<int>& order)
    {
        order.emplace_back(node->val);
        
        if(node->left)
            dfs(node->left,order);
        else
            order.emplace_back(INT_MAX);
        if(node->right)
            dfs(node->right,order);
        else
            order.emplace_back(INT_MAX);
    }
    
    bool contains_bf(vector<int>& a, vector<int>& b)
    {   //暴力解法
        for(int i = 0 ; i < (int)main_order.size() - (int)sub_order.size() + 1; ++i)
        {
            int k = i;
            bool isMatched = true;
            for(int j = 0; j < sub_order.size(); ++j)
            {
                //cout << main_order[k] << ":" << sub_order[j] << endl;
                if(main_order[k] != sub_order[j])
                {
                    isMatched = false;
                    break;
                }
                ++k;
            }
            if(isMatched)
                return true;
        }
        return false;        
    }
    
    
    void build_next(vector<int>& next,const vector<int>& pat)
    {
        //next数组：kmp的子串匹配指导数组。
        next[0] = 0;
        //next数组第一个永远是0，后面的要算
        for(int i = 1; i < pat.size(); ++i)
        {
            int cur = i - 1;
            
            //第i个元素 每个要和哪个比较，取决于next[i - 1]
            while(pat[next[cur]] != pat[i])
            {
                if(cur == 0)//如果已经走到0了，就没法继续找next指向的前一个索引了，跳出。
                    break;
                else
                    //如果比较以后发现不匹配，那么下一轮就是next[next[i - 1] - 1]
                    cur = next[cur] - 1 < 0 ? 0 : next[cur] - 1;                    
            }
            
            //对于已经走到最左边，还是匹配不上的，就设next为 0
            if(cur == 0 && pat[0] != pat[i])
                next[i] = 0;
            else
                //否则，就是next[当前比较的索引] + 1
                next[i] = next[cur] + 1;    
        }
    }
        
    bool contains_kmp(vector<int>& a, vector<int>& b)
    {  
        vector<int> next(b.size());
        build_next(next,b);
        
        //kmp匹配：主串上的指针i永远是递增，而子串上的指针j在出现失配以后会根据next数组的指示往前倒。
        int i = 0, j = 0;
        while(j < b.size())//因为匹配不上，子串（模式串）指针会往前倒，如果循环跑完了，就意味着匹配成功。
        {
            if(i >= a.size())//子串循环没跑完，主串跑完了，说明匹配失败了。
                return false;
            
            if(b[j] != a[i])//出现失配
            {
                //next[j - 1]的含义是：在这里出现失配以后，我们子串当前指针的左侧应当有多少个元素。
                //如果我们已经匹配了6个，next[j - 1]是3个，这意味着我们应该指向第四个（左侧有0,1,3 三个元素）
                //匹配了6个，意味着 j = 6（循环 j = 0,1,2,3,4,5都顺利跑完了，我们目前位于 j = 6出现了失配）
                //我们用 j 减去 next[j - 1]  6 - 3 = 3，指针指向[3]，左边有三个元素，分别是[0],[1],[2]。

                int change = j - 1 < 0 ? 0 : j - next[j - 1];
                j -= change;
                
                //是否会出现死循环？ 假设我们指针指向第二个元素，也就是说左边有一个元素,j = 1
                //而next[j - 1] = 1 告诉我们，我们左侧应该有一个元素。
                // j - next[j - 1] = 0, j -= 0 = j 这时候出现了死循环。
                 if(change == 0)//因此，当j的变化量为0的时候，我们没有必要，也不能重新跑一个一模一样的循环，而是应该递增主串的指针。
                    ++i;
            }   
            else
            {
                ++i;
                ++j;
            }
        }
        //模式串顺利跑完了，说明找到了模式串，否则模式串的指针j会被next数组控制往后倒，不会出现跑完的情况。
        return true;
    }
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root,main_order);
        dfs(subRoot,sub_order);
        //得到了序列，接下来可以用kmp 也可以不用
        //contains_bf
        //进一步优化的空间：并不要整个树遍历完交给kmp，而是穿插执行2个DFS，一边生成序列一边实时跑kmp，匹配成功直接返回。
        return contains_kmp(main_order, sub_order);
    }
};