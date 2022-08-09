class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        vector<int> res;
        int n(size(potions));
        sort(begin(potions), end(potions));
        
        for (auto& spell : spells) {
            int start(0), end(n);
            while (start < end) {
                int mid = start + (end-start)/2;
                ((long long)spell*potions[mid] >= success) ? end = mid : start = mid+1;
            }
            res.push_back(n-start);
        }
        return res;
    }
};
