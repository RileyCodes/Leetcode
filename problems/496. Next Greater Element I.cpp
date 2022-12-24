class Solution {
public:
    
    /*For an O(N) solution, we will need to use stack
    but why? lets see following example.
    [2,1,3,4]
    
    To find the next greater element for 2, we will need to check 1 and 3 and found 3 is the next greater element.
    
    It means the solution of 3 will also be the solution for the numbers between 2 and 3, which means it is the solution for 1.
    This is because on the constraints we alreayd know that all numbers will be unique, therefore if its not greater than 2, it has to be less and 2. in that case it will share the same next greater element with 2.
    
    To do this in one pass, we will push every element that is smaller than top of the stack into the stack, and pop when we encounter one element that is greater than top of the stack ,which will be the next greater element to every elements in the stack.
    For example, we will have s [2,1] the top is 1. when we encounter 3, we find 3 > 1
    we will pop 1 and 2 out.
    */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        
        //For those did not found an answer, it will be -1 by default.
        for(int i = 0 ; i < ans.size(); ++i)
        {
            ans[i] = -1;
        }
        
        //Since every number is unique, lets use map to record element value and their index.
        unordered_map<int,int> m;
        for(int i = 0; i < nums1.size(); ++i)
        {
            m[nums1[i]] = i;
        }
        
        stack<int> s;
        
        //check from left to right
        for(int i = 0; i < nums2.size(); ++i)
        {
            //if stack is not empty and we found a greater number than the element at the top of the stack, pop and record current index into ans via map.
            while(!s.empty() && nums2[i] > s.top())
            {
                ans[m[s.top()]] = nums2[i];
                s.pop();
            }
            
            //if a element requires an answer(exists in nums1), we will push it into stack.
            if(m.count(nums2[i]) > 0)
            {
                s.push(nums2[i]);
            }
        }
        return ans;
    }
};