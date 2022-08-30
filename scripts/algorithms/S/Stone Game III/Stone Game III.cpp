// Runtime: 312 ms (Top 80.63%) | Memory: 135.9 MB (Top 49.12%)
class Solution {
public:

    int dp[50001][2][2];

    int playGame(vector<int>& stones, bool alice, bool bob, int i) {

        if (i >= stones.size()) return 0;

        int ans;
        int sum = 0;

        if (dp[i][alice][bob] != -1) return dp[i][alice][bob];

        if (alice) {
            ans = INT_MIN;
            for (int idx=i; idx < i + 3 && idx < stones.size(); idx++) {
                sum += stones[idx];
                ans = max(ans, sum + playGame(stones, false, true, idx + 1));
            }
        }

        if (bob) {
            ans = INT_MAX;
            for (int idx=i; idx < i + 3 && idx < stones.size(); idx++) {
                sum += stones[idx];
                ans = min(ans, playGame(stones, true, false, idx + 1));
            }
        }

        return dp[i][alice][bob] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp, -1, sizeof dp);
        int totalScore = 0;
        for (auto i : stoneValue) totalScore += i;
        int aliceScore = playGame(stoneValue, true, false, 0);
        if (totalScore - aliceScore > aliceScore)
            return "Bob";
        else if (totalScore - aliceScore < aliceScore)
            return "Alice";
        else return "Tie";
    }
};