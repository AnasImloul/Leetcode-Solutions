class Solution {
    int dfs(unordered_map<string, int>& m, unordered_set<string>& setWords, 
            const string& w) {
        if (m.count(w)) return m[w];
        int maxLen = 1;
        
        for(int i=0;i<w.size();++i) {
            auto preWord = w.substr(0, i) + w.substr(i+1);
            if(setWords.count(preWord)) {
                int newLen = 1 + dfs(m, setWords, preWord);
                maxLen = max(newLen, maxLen);
            }
        }
        m[w] = maxLen;
        return maxLen;
        
    }
public:
    int longestStrChain(vector<string>& words) {
        
        unordered_map<string, int> m;
        unordered_set<string> setWords(words.begin(), words.end());
        int res = 0;
		
        for(auto& w:words) {
            res = max(res, dfs(m, setWords, w));
        }
        return res;
    }
};
