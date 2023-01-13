class Solution {
public:

    unordered_map<char,char> parents;

    char find(char v)
    {
        if(parents.count(v) == 0)
            parents[v] = v;
        if(v == parents[v])
            return v;
        parents[v] = find(parents[v]);
        return parents[v];
    }

    void _union(char a, char b)
    {
        char pA = find(a);
        char pB = find(b);
        if(pA == pB)
            return;
        parents[pA] = pB;
    }

    bool equationsPossible(vector<string>& equations) {
        //three different 
        for(auto&& equation : equations)
        {
            char a = equation[0];
            bool isEQ = equation[1] == '=';
            char b = equation[3];
            /* if a or b does not have a parents, it means they can have connection with anything
            in case of a == b, it means a and b are in same graph
            in case of a != b, it means a and b cannot be in the same graph 
            if a != b and they are not in the same graph, no action is required.
            if a != b and both of them are not in any graph, we shell make them as the representation node for their own graph.
            if a != b but they are in same graph, returns false
            if a != b and only one node its not in any graph, such node shell be the represenation node of its own graph

            if a == b but a and b alreaady presents in different graph, returns false
            if a == b and a and b is in the same graph, no actions required'
            if a == b and one of them is not in any graph, union it with the other node.
            ...*/
            if(isEQ)
                _union(a,b);
            /*
            if(isEQ)
            {
                if(!parents.count(a) || !parents.count(b))
                    
                else if(find(a)  != find(b))
                    return false;
            }
            else
            {
                if(find(a) == find(b))
                    return false;
            }            
            */
        }

        for(auto&& equation : equations)
        {
            char a = equation[0];
            bool isEQ = equation[1] == '=';
            char b = equation[3];
            if(!isEQ && find(a) == find(b))
                return false;
        }

        return true;
    }
};
