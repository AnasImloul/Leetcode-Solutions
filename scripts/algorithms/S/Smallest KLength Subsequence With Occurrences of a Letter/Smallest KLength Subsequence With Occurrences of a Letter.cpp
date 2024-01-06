// Runtime: 124 ms (Top 95.4%) | Memory: 28.70 MB (Top 90.8%)

class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int rest = count(s.begin(), s.end(), letter); 
        string ans; 
        for (int i = 0, n = s.size(); i < n; ++i) {
            while (ans.size() && ans.back() > s[i] && ans.size() + n - i > k && (ans.back() != letter || repetition < rest)) {
                if (ans.back() == letter) repetition += 1; 
                ans.pop_back(); 
            }
            if (ans.size() < k && (s[i] == letter || ans.size() + repetition < k)) {
                ans.push_back(s[i]); 
                if (s[i] == letter) repetition -= 1; 
            }
            if (s[i] == letter) --rest; 
        }
        
        return ans; 
    }
};
