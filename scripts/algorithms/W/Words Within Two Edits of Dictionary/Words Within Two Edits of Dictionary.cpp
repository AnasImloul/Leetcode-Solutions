// Runtime: 14 ms (Top 67.63%) | Memory: 9.70 MB (Top 68.21%)

class Solution {
public:
    int n;
    
    bool canFit(string& word, vector<string>& dict) {
        int i, score;
        for(string& d: dict) {
            score = 0;
            for(i = 0; i < n; i++) {
                if(word[i] == d[i])
                    score++;
            }
            if(score >= n - 2)
                return true;
        }
        
        return false;
    }
    
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        n = dictionary[0].length();
        vector<string> res;
        
        for(string& word: queries)
            if(canFit(word, dictionary))
                res.push_back(word);
        
        return res;
    }
};
