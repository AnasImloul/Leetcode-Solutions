class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> freq;
        for (auto num : nums) if (num.size() < target.size()) freq[num]++;
        
        int res = 0;
        for (auto [s, frq] : freq) {
            
            if (target.find(s) == 0) {
                
                if (s + s == target) 
                    res += frq*(frq-1);
                
                else 
                    res += frq * freq[target.substr(s.size())];
            }
        }
        
        return res;
    }
};
