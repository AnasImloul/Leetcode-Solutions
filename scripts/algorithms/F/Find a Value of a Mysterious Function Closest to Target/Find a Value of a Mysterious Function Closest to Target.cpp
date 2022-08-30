// Runtime: 195 ms (Top 98.04%) | Memory: 62.7 MB (Top 95.42%)
class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        vector<int> q;
        q.reserve(32);
        int best = 1'000'000'000;
        for (size_t i = 0; i < arr.size(); i++) {
            for (auto& x : q) x &= arr[i];
            q.push_back(arr[i]);
            q.erase(unique(begin(q), end(q)), end(q));
            for (auto x : q) best = min(best, abs(target-x));
        }
        return best;
    }
};