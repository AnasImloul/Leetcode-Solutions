// Runtime: 678 ms (Top 33.18%) | Memory: 115.3 MB (Top 49.54%)
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {

        int res (INT_MAX), n(size(cards));
        unordered_map<int, int> m;
        for (auto i=0; i<n; i++) {
            // number of consecutive cards you have to pick up to have a pair of matching cards == (Diference between 2 indexes of same card) + 1
            if (m.count(cards[i])) res = min(res, i-m[cards[i]]+1);
            m[cards[i]] = i;
        }
        return (res == INT_MAX) ? -1 : res;
    }
};