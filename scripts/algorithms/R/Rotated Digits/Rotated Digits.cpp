// Runtime: 3 ms (Top 69.84%) | Memory: 7 MB (Top 11.11%)
class Solution
{
public:
    bool isValid(int n)
    {
        bool check = false;
        while (n > 0)
        {
            int k = n % 10;
            if (k == 2 || k == 5 || k == 6 || k == 9)
                check = true;
            if (k == 3 || k == 4 || k == 7)
                return false;
            n /= 10;
        }
        return check;
    }
    int rotatedDigits(int n)
    {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++)
        {
            if (isValid(i))
                dp[i]++;
            dp[i] += dp[i - 1];
        }
        return dp[n];
    }
};