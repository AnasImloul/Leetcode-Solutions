// Runtime: 0 ms (Top 100.0%) | Memory: 6.90 MB (Top 63.9%)

class Solution {
    public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    
    int atMostK(string &s, int k) {
        int res = 0, i=0, n = s.size();
        unordered_map<char, int> mp;
        
        for(int j=0; j<n; j++) {
            if (!isVowel(s[j])) {
                i = j + 1;
                //Clear map as new substring will begin
                mp.clear();
                continue;
            }
            mp[s[j]]++;
            while(mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
    
    int countVowelSubstrings(string str) {
        return atMostK(str, 5) - atMostK(str, 4);
    }
};
