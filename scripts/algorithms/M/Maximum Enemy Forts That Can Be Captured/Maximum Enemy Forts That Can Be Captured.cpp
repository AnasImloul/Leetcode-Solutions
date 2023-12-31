// Runtime: 0 ms (Top 100.0%) | Memory: 7.90 MB (Top 99.15%)

class Solution {
public: 
    int captureForts(vector<int>& forts) {
        int ans = 0; 
        for (int i = 0, ii = 0; i < forts.size(); ++i) 
            if (forts[i]) {
                if (forts[ii] == -forts[i]) ans = max(ans, i-ii-1); 
                ii = i; 
            }
        return ans; 
    }
};
