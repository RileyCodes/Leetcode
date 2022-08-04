class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        /*
        这道题我们得到了一堆闭区间，准确来说是2个包含了多个闭区间的数组
        每个数组内部的闭区间不相交，而且排序过了
        
        我们要找出2个数组内部相交部分的区间，并且把这些相交区间作为第三个数组返回。
        
        这道题我们可以抓着其中一个数组作为基点来操作，比如说以firstList为基点。
        
        然后我们现在只盯着这个数组的第一个元素，比如说[a,b]
        
        现在考虑和另一个数组的区间比较会发生哪些情况：
        1.另一个数组在这个数组左边，双方不相交，没有东西
        2.另一个数组在这个数组的左边，右边部分相交了，也就是[a,b],[c,d]中， a <= d <= c
        3.另一个数组在这个数组的里面，也就是[a,b],[c,d]中， a <= c <= d 且 a <= d <= c
        4.另一个数组覆盖了这个数组的所有区间，，也就是[a,b],[c,d]中 c <= a <= d 且 c <= b <= d
        5.另一个数组在这个数组的右边，左边部分相交了，也就是[a,b],[c,d]  a <= c <= b
        6.另一个数组在这个数组的右边，完全没相交。
        
        另外需要注意的是，一个数组可能和多个数组相交，比如说[10,20]里面可能和[5,11],[12,12],[14,16]相交。 
        
        如果当前区间有任何一头被包在另一个区间里面，或者另一个区间有任何一头被包在这个区间里面，那么我们就可以认为有相交需要处理。
        
        怎么判定当前数组的所有相交都处理完了，移向下一个数组？
        
        每次处理都是2个区间之间的处理，在处理之后，其中一个的右边界必然大于或者等于另一个区间的边界。
        比如说[3,6][5,6]的情况下，因为2个的右边界都是6，所以这时候哪个移向下一个都可以
        如果是[3,6][4,5]的情况下，对于[3,6] 我们并不能肯定处理完了，因为另一边可能还会出现[6,6]这种区间
        但是对于[4,5]，因为另一边的右区间大于自己的右区间(5 > 6)，所以我们可以确定处理完了，因此我们可以走到[4,5]的下一个区间。
        
        */
        
        int pFirst = 0, pSecond = 0;//定义2个区间数组的指针
        vector<vector<int>> result;
        
        //如果其中一个走到头了，另一边肯定无法产生相交的区间了，所以不用继续跑了。
        while(pFirst < firstList.size() && pSecond < secondList.size())
        {
            //判断second和first有相交
            
            //第二区间的左节点在第一区间的左右节点之间
            if((firstList[pFirst][0] <= secondList[pSecond][0] && firstList[pFirst][1] >= secondList[pSecond][0]) ||
               
               //第二区间的右节点在第一区间的左右节点之间
               (firstList[pFirst][0] <= secondList[pSecond][1] && firstList[pFirst][1] >= secondList[pSecond][1]) || 
               
               //第一区间的左节点在第二区间的左右节点之间
               (secondList[pSecond][0] <= firstList[pFirst][0] && secondList[pSecond][1] >= firstList[pFirst][0]) || 
               
               //第一区间的右节点在第二区间的左右节点之间
               (secondList[pSecond][0] <= firstList[pFirst][1] && secondList[pSecond][1] >= firstList[pFirst][1])
              )
            {
                //这些情况下可以肯定2个区间有相交，无论他们具体是如何相交的，我们取2个区间左边界的最大值和右边界的最小值。
                vector<int> unionInterval;
                unionInterval.emplace_back(max(firstList[pFirst][0], secondList[pSecond][0]));
                unionInterval.emplace_back(min(firstList[pFirst][1], secondList[pSecond][1]));
                result.emplace_back(unionInterval);
            }
            //当走到这里的时候，我们有2个情况，一个是我们指针指着2个相交的区间，但是我们已经把相交的部分加入到了结果里面。
            //还一个情况是2个区间根本没相交。 但是不论是哪个情况，2个区间至少有一个已经被彻底处理完了，指针应该移向下一个区间。
            
            if(firstList[pFirst][1] >= secondList[pSecond][1])
            {
                //如果第一个区间比第二个区间的右边界大，这意味着第二个区间已经被处理完了
                //如果相等，那么移动哪个都可以，我们就移第一个了
                ++pSecond;
            }
            else//否则，说明第二个区间比第一个大，我们应该移第一个的指针。
                ++pFirst;
        }
        
        return result;
    }
};