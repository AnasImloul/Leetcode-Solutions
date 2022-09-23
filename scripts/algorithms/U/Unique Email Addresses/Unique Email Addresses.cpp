// Runtime: 22 ms (Top 96.52%) | Memory: 13.7 MB (Top 81.90%)
class Solution {
public:
    int numUniqueEmails(vector<string>& emails)
    {
        unordered_set<string> st;
        for(auto &e:emails)
        {
            string clean_email="";
            for(auto &ch:e)
            {
                if(ch=='+'||ch=='@')
                    break;
                if(ch=='.')
                    continue;
                clean_email+=ch;
            }
            clean_email+=e.substr(e.find('@'));
            st.insert(clean_email);
        }
        return st.size();

    }
};
//if you like the solution plz upvote.