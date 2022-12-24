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

    sort(skill.begin(),skill.end());

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