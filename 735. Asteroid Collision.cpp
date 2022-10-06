class Solution {
public:
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        while(1)
        {
            bool something_happened = false;
            int slow = 0, fast = 1;
            
            while(1)
            {
                while(slow < asteroids.size() )
                {
                    if(asteroids[slow] == 0)
                        ++slow;
                    else
                        break;
                }       
                
                fast = slow + 1;
                
                while(fast < asteroids.size())
                {
                    if(asteroids[fast] == 0)
                        ++fast;
                    else
                        break;
                }

                if(slow >= fast || fast >= asteroids.size())
                    break;
                
                if(asteroids[fast] < 0 && asteroids[slow] > 0)
                {
                    something_happened = true;
                    int left = abs(asteroids[slow]);
                    int right = abs(asteroids[fast]);
                    if(left > right)
                        asteroids[fast] = 0;
                    else if(left < right)
                        asteroids[slow] = 0;
                    else
                    {
                        asteroids[slow] = 0;
                        asteroids[fast] = 0;
                    }
                }            
                ++slow;
                ++fast;
            }

            if(!something_happened)
                break;
        }

        
        vector<int> ans;
        for(auto ele : asteroids)
        {
            if(ele == 0)
                continue;
            ans.emplace_back(ele);
        }
        return ans;
    }
};