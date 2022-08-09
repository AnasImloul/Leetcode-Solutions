class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map <char,unordered_set<string>> mp;
        for(auto u : ideas) mp[u[0]].insert(u.substr(1,u.size()-1));
        
        long long ans = 0;
        
        for(int i = 0; i<26; i++){
            for(int j = i+1; j<26; j++){
                unordered_set <string> s1 = mp[i+'a'], s2 = mp[j+'a'];
                
                int comm = 0;
                for(auto u : s1)
                    if(s2.find(u)!=s2.end()) comm++;
                
                ans += (long long)(s1.size()-comm)*(long long)(s2.size()-comm)*2;
            }
        }
        return ans;
    }
};
