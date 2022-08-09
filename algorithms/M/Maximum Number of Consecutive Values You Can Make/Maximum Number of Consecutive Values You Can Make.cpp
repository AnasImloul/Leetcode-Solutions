class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        // support variables
        int res = 1;
        // preparing coins
        sort(begin(coins), end(coins));
        for (int coin: coins) {
            // checking if we could have reached coin without gaps
            if (res >= coin) res += coin;
            else break;
        }
        return res;
    }
};
