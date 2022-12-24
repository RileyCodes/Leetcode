class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int curEnergy = initialEnergy;
        int curExperience = initialExperience;
        int diff = 0;
        for(int i =0; i < experience.size();++i)
        {
            if(energy[i] >= curEnergy)
            {
                diff += energy[i] - curEnergy + 1;
                curEnergy +=  energy[i] - curEnergy + 1;
            }
        
 
            if(experience[i] >= curExperience)
            {
                diff += experience[i] - curExperience + 1;
                curExperience  += experience[i] - curExperience + 1;

            }
            
            
            curEnergy -= energy[i];
            curExperience += experience[i];
        }
        return diff;
    }
};