// Runtime: 557 ms (Top 57.30%) | Memory: 24.5 MB (Top 81.25%)

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words[0].length();
        int slen = s.length();
        int len = slen - n*words.size();
        vector<int> ans;
        if( len < 0) return ans;
        string t;
        unordered_map<string, int> mp;
        for(auto i = 0; i < words.size(); ++i) ++mp[words[i]];

        for(int i = 0; i<= len; ++i){
            t = s.substr(i, n);
            if(mp.find(t) != mp.end()){
                unordered_map<string, int> smp;
                ++smp[t];
                int flag = 1;
                for(int j = i+n, k = 1; k < words.size() && j+n <= slen; ++k, j = j + n){
                    t = s.substr(j, n);
                    if(mp.find(t) != mp.end()) ++smp[t];
                    else {
                        flag = 0;
                        break;
                    }
                }
                if(flag && smp == mp) ans.push_back(i);
            }
        }

        return ans;
    }
};