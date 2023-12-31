// Runtime: 26 ms (Top 66.54%) | Memory: 14.90 MB (Top 76.54%)

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int s) {
        int n = words.size(), ans = INT_MAX;
        
        for(int i = 0; i < n; i++) 
            if(words[i] == target) 
                ans = min(ans, min(abs(s - i), abs(n - abs(s - i)))); 
                // abs(s - i) => distance from starting index to target index, 
                // abs(n - abs(s - i)) => distance from starting index to target index but reverse direction
        
        return ans == INT_MAX ? -1 : ans;
    }
};
