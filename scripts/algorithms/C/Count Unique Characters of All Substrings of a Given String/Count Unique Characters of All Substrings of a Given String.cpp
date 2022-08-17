class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> counting(26);
        int ans = 0;
        
        // step 1: record the position for each char;
        for(int curr = 0; curr < 26; curr++){
            counting[curr].push_back(-1);
        }
        
        for(int curr = 0; curr < s.size(); curr++){
            counting[s[curr] - 'A'].push_back(curr);
        }
        
        for(int curr = 0; curr < 26; curr++){
            counting[curr].push_back(s.size());
        }
        
        // step 2: for each char in s, find the # of contrubution for substring;
        for(int curr = 0; curr < 26; curr++){
            for(int pos = 1; pos < counting[curr].size() - 1; pos++){
                ans += (counting[curr][pos] - counting[curr][pos - 1]) * (counting[curr][pos + 1] - counting[curr][pos]);
            }
        }
        
        return ans;     
    }
};
