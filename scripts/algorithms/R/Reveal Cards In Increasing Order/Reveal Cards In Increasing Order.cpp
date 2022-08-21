// Runtime: 13 ms (Top 15.03%) | Memory: 8.4 MB (Top 85.90%)

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size(), idx = 0, idx1 = 0;
        vector<int> res(n, -1);
        sort(deck.begin(), deck.end());
        bool found = 1;
        while(idx < n) {
            if(res[idx1] == -1 and found) {
                res[idx1] = deck[idx]; found = 0; idx++;
            }
            else if(res[idx1] == -1) found = 1;
            idx1 = (idx1 +1)%n;
        }
        return res;
    }
};