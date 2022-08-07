class Solution {
public:
    // checks if s2 is scrambled form of s1
    /*
        The idea is to find a position in string s1, from where scrambling must have
        started to create s2. So if k is the position, then s1[0-k] and s1[k+1, N-1]
        were the last scramble op. We do this recursively for the smaller substrings.
        
    */
    bool isScrambled(int s1_start, int s1_end, int s2_start, int s2_end,
                    string& s1, string& s2, unordered_map<string, bool>& dp) {
        // create the current position combination
        string curr_cmb = to_string(s1_start) + ',' + to_string(s1_end) + 
                            ',' + to_string(s2_start) + ',' + to_string(s2_end);
        // check if the values is in cache 
        auto it = dp.find(curr_cmb);
        if(it != dp.end())
            return dp[curr_cmb];
        
        // base cases
        if(s1_end < s1_start || s2_end < s2_start)
            return false;
        // if the size of two strings is diff, then scrambling not poss
        if(s1_end - s1_start != s2_end - s2_start)
            return false;
        // if the two substrings match, then they are scrambled
        if(s1.substr(s1_start, s1_end - s1_start + 1) == s2.substr(s2_start, s2_end - s2_start + 1))
            return true;
        
        // check if the two substrings contains the same set of chars
        vector<int> char_freq(256, 0);
        for(int i = 0; i <= s1_end - s1_start; i++)
            char_freq[s1[s1_start + i]-'a']++, char_freq[s2[s2_start + i]-'a']--;
        for(int i = 0; i < 256; i++)
            if(char_freq[i]) 
				return false;
        
        // find a position which is the potential scramble point
        for(int k = 0; k < (s1_end - s1_start); k++) {
            // check for s1[start: k], s2[start:k] and s1[k+1 : end], s2[k+1 : end]
            if(isScrambled(s1_start, s1_start + k, s2_start, s2_start + k, s1, s2, dp)  &&
              isScrambled(s1_start + k + 1, s1_end, s2_start + k + 1, s2_end, s1, s2, dp))
                return dp[curr_cmb] = true;
            // Now incase of s2, maybe scramble opertation was performed at k, so 
            // now check if the other half of s2
            // check for s1[start: k], s2[end - k : end] and s1[k+1 : end], s2[s : end - k - 1]
            if(isScrambled(s1_start, s1_start + k, s2_end - k, s2_end, s1, s2, dp)  &&
              isScrambled(s1_start + k + 1, s1_end, s2_start, s2_end - k - 1, s1, s2, dp))
                return dp[curr_cmb] = true;
        }
        return dp[curr_cmb] = false;
    }
    
    bool isScramble(string s1, string s2) {
        // DP cache: saves the result of (s1_start, s1_end, s2_start, s2_end) cmb
        unordered_map<string, bool> dp;
        return isScrambled(0, s1.size()-1, 0, s2.size()-1, s1, s2, dp);
    }
};
