class Solution
{
public:
    int integerBreak(int n)
    {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        if (n == 4)
            return 4;
        int k = n / 3;
        int m = n % 3;
        int ans;
        if (m == 0)
            ans = pow(3, k);
        else if (m == 1)
            ans = pow(3, k - 1) * 4;
        else if (m == 2)
            ans = pow(3, k) * m;
        return ans;
    }
};
