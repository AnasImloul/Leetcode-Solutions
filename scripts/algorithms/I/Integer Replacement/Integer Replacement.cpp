// Runtime: 11 ms (Top 9.31%) | Memory: 5.9 MB (Top 81.51%)
class Solution {
public:
    int integerReplacement(int n) {

        return helper(n);
    }

    int helper(long n)
    {
        if(n == 1)
            return 0;

        if(n % 2)
            return 1 + min(helper(n - 1), helper(n + 1));

        return 1 + helper(n / 2);
    }
};