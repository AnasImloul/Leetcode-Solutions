// Runtime: 0 ms (Top 100.0%) | Memory: 10.50 MB (Top 58.44%)

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<int, int> m1;
        int mn = INT_MIN;
        int all_same = count(begin(suits), end(suits), suits[0]);
        int n = ranks.size();
        for (int i = 0; i < n; i++) {
            m1[ranks[i]]++;
            mn = max(mn, m1[ranks[i]]);
        }
        if (all_same == n)     return "Flush";
        if (mn >= 3)      return "Three of a Kind";
        if (mn == 2)      return "Pair";
        return "High Card";
    }
};
