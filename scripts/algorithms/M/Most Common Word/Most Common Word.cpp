// Runtime: 8 ms (Top 56.16%) | Memory: 7.9 MB (Top 32.68%)
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned)
    {
         unordered_set<string> ban(banned.begin(),banned.end());
        unordered_map<string,int> m;
        for(auto &c:paragraph)
        {
            c=isalpha(c)?tolower(c):' ';
        }
        istringstream s(paragraph);
        string w;
        pair<string,int> res({"",0});

        while (s >> w)
        {
            if (ban.find(w) == ban.end() && ++m[w] > res.second)
            {
                res = make_pair(w, m[w]);
            }
        }
        return res.first;

    }
};
//if you like the solution plz upvote.