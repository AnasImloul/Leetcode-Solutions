// Runtime: 0 ms (Top 100.00%) | Memory: 7.5 MB (Top 53.55%)

class Solution {
    string preprocessing(string &f, int space, int limit)
    {
        int noofspace = limit-f.size()+space;
        int k = 0;
        string r = "";
        while(space)
        {
            int n = noofspace / space;
            if((noofspace%space) != 0)
                n += 1;
            noofspace -= n;
            while(f[k] != ' ')
            {
                r += f[k];
                k++;
            }
            k++;
            while(n--)
            {
                r += ' ';
            }
            space--;
        }
        while(k < f.size())
        {
            r += f[k];
            k++;
        }
        while(noofspace--)
            r += ' ';
        return r;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string f = "";
        int space = 0;
        for(string &str : words)
        {
            if((f.size() + str.size() + 1) <= maxWidth && f.size() > 0)
            {
                f += ' ' + str;
                space++;
            }
            else
            {
                if(f.size() > 0){
                    f = preprocessing(f, space, maxWidth);
                    ans.push_back(f);
                    f = "";
                }
                f += str;
                space = 0;
            }
        }
        int sz = f.size();
        while(sz < maxWidth)
        {
            f += ' ';
            sz++;
        }
        ans.push_back(f);
        return ans;
    }
};