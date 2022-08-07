class Solution
{
public:
    string toHex(int num)
    {
        string hex = "0123456789abcdef";
        unsigned int n = num; // to handle neg numbers
        string ans = "";
        if (n == 0)
            return "0";
        while (n > 0)
        {
            int k = n % 16;
            ans += hex[k];
            n /= 16;
        }
        reverse(ans.begin(), ans.end()); // as we stored it in the opposite order
        return ans;
    }
};
