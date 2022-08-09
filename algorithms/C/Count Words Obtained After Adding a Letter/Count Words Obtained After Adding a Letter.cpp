class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
	// generates hashes for startWords.
        unordered_set<int> vis;
        for (string s : startWords) {
            int hash = 0;
            for (int i = 0; i < s.size(); i++) {
                hash += (1 << (s[i] - 'a'));
            }
            vis.insert(hash);
        }
        
		// check each target Word
        int res = 0;
        for (string s : targetWords) {
            int hash = 0;
            // k is the index of character we remove
            for (int k = 0; k < s.size(); k++) {
                hash = 0;
                for (int i = 0; i < s.size(); i++) {
                    if (i == k) continue;
                    hash += (1 << (s[i] - 'a'));
                }
                if (vis.count(hash)) {
                    res++;
                    break;
                }
            }
        }
        
        return res;
    }
};
