class Solution {
public:

    bool canReach(string s, int minJump, int maxJump) {
        int leftBound = 1;
        queue<int> q;
        q.push(0);
        q.push(-1);
        while(!q.empty())
        {
            int index = q.front();
            q.pop();
            if(index == -1)
            {
                q.push(-1);
                if(q.front() == -1)
                    break;
                continue;
            }
            if(index == s.size() - 1)
                return s[index] == '0';

            int moveableMin = index + minJump;
            int moveableMax = min(index + maxJump, (int)s.size() - 1);        
            for(int i = max(leftBound,moveableMin); i <= moveableMax; ++i)    
            {
                if(s[i] == '0')
                    q.push(i);
                leftBound = i + 1;
            }
        }

        return false;
    }
};