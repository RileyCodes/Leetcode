class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

    /*
        You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

        The chemistry of a team is equal to the product of the skills of the players on that team.

        Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.    
    */

    //Divide the players into n / 2 teams: Since the skill array are even, it is always possibile to divide into n / 2 teams
    //However, the total skill of each team must be equal.

    //How to we know we can divide the players into teams such that that the total skill of each team is equal?



    int teamSkills = -1;

    int maxVal = *max_element(skill.begin(), skill.end()); // O(n)

    // Loop from the least significant digit to the most significant digit
    for(int exp = 1; maxVal / exp > 0; exp *= 10) //O(log(maxVal)) = O(1)
    {
        // Count the number of occurrences of each digit in the array
        vector<int> count(10, 0);
        for(auto i : skill) // O(n)
            count[(i / exp) % 10]++;

        // Sort the array according to the current digit
        vector<int> output(skill.size());
        for(int i = 1; i < 10; i++)  //O(1), prefix sum
            count[i] += count[i - 1];
        for(int i = skill.size() - 1; i >= 0; i--)// O(n)
        {
            output[count[(skill[i] / exp) % 10] - 1] = skill[i];
            count[(skill[i] / exp) % 10]--;
        }

        // Copy the sorted array back to the original array
        for(int i = 0; i < skill.size(); i++)// O(n)
            skill[i] = output[i];
    }

    int lP = 0, rP = skill.size() - 1;
    vector<pair<int,int>> teams;
    long long chem = 0;
    while(lP < rP)
    {
        if(teamSkills > 0)
        {
            if(skill[lP] + skill[rP] != teamSkills)
                return -1;
        }
        else
            teamSkills = skill[lP] + skill[rP];

        // Calculate the chemistry of the current team
        chem += skill[lP] * skill[rP];

        ++lP;
        --rP;
    }
        return chem;
    }
};