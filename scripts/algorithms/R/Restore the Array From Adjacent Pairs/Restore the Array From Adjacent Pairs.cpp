// Runtime: 327 ms (Top 69.44%) | Memory: 106.00 MB (Top 74.11%)

class Solution {
public:
    std::vector<int> restoreArray(std::vector<std::vector<int>>& vals) {
        std::unordered_map<int, std::vector<int>> pairs;
        
        for (const std::vector<int>& val : vals) {
            pairs[val[0]].push_back(val[1]);
            pairs[val[1]].push_back(val[0]);
        }
        
        std::vector<int> result;
        int start = -1000000;
        
        for (const auto& entry : pairs) {
            if (entry.second.size() == 1) {
                start = entry.first;
                break;
            }
        }
        
        int left = -1000000;
        result.push_back(start);
        
        for (int i = 1; i < vals.size() + 1; ++i) {
            const std::vector<int>& val = pairs[start];
            int newval = (val[0] == left) ? val[1] : val[0];
            result.push_back(newval);
            left = start;
            start = newval;
        }
        
        return result;
    }
};
