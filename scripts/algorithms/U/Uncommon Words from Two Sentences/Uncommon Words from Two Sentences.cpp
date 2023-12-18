// Runtime: 4 ms (Top 47.05%) | Memory: 7.20 MB (Top 56.72%)

class Solution {
public:
    void uncommon(string s,unordered_map<string,int>&mp) {
        string word="";
        for(int i=0; i<s.size(); i++) {
                if(s[i]==' ') {
                     mp[word]++;
                     word="";
                }else {
                     word+=s[i];
                }
        }
        mp[word]++;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string,int> mp;
        uncommon(s1,mp);
        uncommon(s2,mp);
        for(pair<string,int> p : mp) {
            if(p.second==1) ans.push_back(p.first);
        }
        return ans;
    }
};
