// Runtime: 4 ms (Top 91.36%) | Memory: 7.1 MB (Top 46.74%)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                for(auto it:mp){
                    if(it.second==t[i])return false;
                }
                mp[s[i]]=t[i];
            }
            else{
                if(mp[s[i]]!=t[i]) return false;

            }

        }
        return true;

    }
};