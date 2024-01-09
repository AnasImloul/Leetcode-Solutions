// Runtime: 3 ms (Top 92.54%) | Memory: 10.30 MB (Top 96.94%)

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans ;
        
        for( auto &it : nums ){
            
            string tmp = to_string(it);
            
            for( auto &s : tmp ) ans.push_back(s-'0');
            
        }
        
        return ans ;
    }
};
