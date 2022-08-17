class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int, int> freq;
        for (auto num : changed) freq[num]++;
        
        sort(changed.begin(), changed.end());
        
        vector<int> res;
        for (auto num : changed) {
            if (freq[num] && freq[num*2]) {
                freq[num]--;
                freq[num*2]--;
                res.push_back(num);
            }
        }
        
        for (auto [a, b] : freq)
            if (b) return {};
        
        return res;
    }
};
