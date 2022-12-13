class Solution {
public:

    bool isMatch(const string& s,const string& p, int indexString, int indexPat)
    {
        /*
        //cout << "indexString: " << indexString << endl;
        //cout << "indexPat: " << indexPat << endl;        

        if(indexPat >= p.size() || indexString >= s.size()) //At the end of pattern.
        {
            if(s.size() == indexString) //At the end of string
            {
                cout << "TRUE" << endl;
                return true; // if its not rejected by prior logic, it should be accepted.     
            }
            if(s.size() < indexString)           
                cout << "s.size() < indexString" << endl;

            //else, we are not at the end of string but at the end of pattern.
            //this case in general should be false, UNLESS the last pattern was a *, would be .* or a*.
            if(p[p.size() - 1] == '*')
            {
                if(p[p.size() - 2] == '.')//if the pat ended with .*, it is an unconditional true.
                    return true;
                else
                {
                    //Else, we need to check if the rest of string mets requirements.
                    cout << "CHECK" << endl;
                    for(int i = indexString; i < s.size();++i)
                    {
                        cout <<s[i];
                        if(s[i] != p[p.size() - 2])
                        {
                            cout << endl;
                            return false;
                        }
                    }
                    return true;
                }
                    
            }
            return false;
        }
        */

        bool wildcardMode = false;
        if(indexPat + 1 < p.size())//Check for wildcard mode.
            wildcardMode = (p[indexPat + 1] == '*');

        //no pattern will accept no string
        if(indexPat >= p.size() && indexString >= s.size())    
            return true;
        
        if(wildcardMode)
        {
            //In a wildcard mode, we can match 0 or more characters with one pattern, we will need to try all the combinations.

            if(indexString >= s.size()) 
            {
                /*
                    the current token,being a wildcard will have no issue accept a empty input, 
                    but we still need to move to next token to ensure there are no non-wildcard token in the remaining pattern.
                */                
                return isMatch(s,p,indexString,indexPat + 2);
            }
            for(int i = indexString; i < s.size(); ++i)
            {
                if(p[indexPat] != '.' && s[i] != p[indexPat])
                {
                    if(indexPat + 2 == p.size())//Match finished
                    {    
                        return false;           
                    }
                                 
                    return isMatch(s,p,i,indexPat + 2);
                }

                if(indexPat + 2 == p.size())//Match finished
                {
                    if(isMatch(s,p,i + 1,indexPat))
                        return true;    
                }
                else if(isMatch(s,p,i,indexPat + 2))
                    return true;    
            }
        }
        else if((p[indexPat] == '.' && indexString < s.size())//pat with '.' will still require at least one chatacter.
        || s[indexString] == p[indexPat])
        {
            if(indexPat + 1 == p.size())//Match finished
            {
                return indexString + 1 == s.size();//No leftover string
            }
            return isMatch(s,p,indexString + 1,indexPat + 1);
        }
            
        return false;
    }

    bool isMatch(string s, string p) {
        return isMatch(s,p,0,0);
    }
};