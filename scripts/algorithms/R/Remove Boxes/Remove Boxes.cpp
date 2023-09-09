// Runtime: 39 ms (Top 92.6%) | Memory: 12.28 MB (Top 69.1%)

class Solution {
public:
    int dp[102][102][102];
    int solve(int i, int j, int extra, vector<pair<int, int>> &groups)
    {
        if (i > j)
            return 0;

        if (dp[i][j][extra] != -1)
            return dp[i][j][extra];

        int ans = (groups[i].second + extra) * (groups[i].second + extra) + solve(i + 1, j, 0, groups);

        for (int g = i + 1; g <= j; g++)
            if (groups[g].first == groups[i].first)
                ans = max(ans, solve(i + 1, g - 1, 0, groups) + solve(g, j, extra + groups[i].second, groups));

        return dp[i][j][extra] = ans;
    }
    int removeBoxes(vector<int> &boxes)
    {
        int n = boxes.size();

        vector<pair<int, int>> groups;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (i + 1 < n and boxes[i + 1] == boxes[j])
                i++;
            groups.push_back({boxes[j], i - j + 1});
        }

        memset(dp, -1, sizeof(dp));
        return solve(0, groups.size() - 1, 0, groups);
    }
};