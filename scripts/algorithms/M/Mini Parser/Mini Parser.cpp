// Runtime: 20 ms (Top 36.02%) | Memory: 13.5 MB (Top 22.22%)
class Solution {
public:
    NestedInteger deserialize(string s) {

        int i = 0;
        return helper(s, i).getList()[0];
    }

    NestedInteger helper(string &s, int &i)
    {
        NestedInteger nI;

        while(i < s.size())
        {
            if(s[i] == ',')
            {
                i++;
                continue;
            }

            if(s[i] == ']')
            {
                i++;
                return nI;
            }

            if(s[i] == '[')
                nI.add(helper(s, ++i));
            else
            {
                string tmp;
                while(i < s.size() && s[i] != ',' && s[i] != ']')
                    tmp += s[i++];

                NestedInteger tmp_nI(stoi(tmp));
                nI.add(tmp_nI);
            }
        }

        return nI;
    }
};