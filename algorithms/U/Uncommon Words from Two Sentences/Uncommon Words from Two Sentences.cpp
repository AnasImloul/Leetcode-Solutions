class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        istringstream s(s1+" "+s2);
        
        unordered_map<string,int> m;
        string str;
        while(s>>str) //take string into str till space 
        {
            m[str]++;
        }
        vector<string> res;
        for(auto &p:m)
        {
            if(p.second==1)
                res.push_back(p.first);
        }
        return res;
        
        
    }
};
// if you like the solution plz upvote.