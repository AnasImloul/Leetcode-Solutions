class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        set<vector<int>> hash;
        for (int i = 0; i < startWords.size(); i++) {
            vector<int> counter(26, 0);
            for (char &x : startWords[i]) {
                counter[x - 'a']++;
            }
            hash.insert(counter); 
        }
        
        
        int ans = 0;
        
        for (int i = 0; i < targetWords.size(); i++) {
            vector<int> counter(26, 0);
            for (char &x : targetWords[i]) {
                counter[x - 'a']++;
            }
            
            for (int j = 0; j < 26; j++) {
                if (counter[j] == 1) {
                    counter[j] = 0;
                    
                    if (hash.find(counter) != hash.end()) {
                        ans++;
                        break;
                    }
                    
                    counter[j] = 1;
                }
            }
        }
        
        return ans;
    }
};