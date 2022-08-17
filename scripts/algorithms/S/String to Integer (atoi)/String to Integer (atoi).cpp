class Solution
{
    public:
        int myAtoi(string s)
        {
            long long ans = 0;
            int neg = 1;
            int i = 0;
            while (i < s.length() and s[i] == ' ')
            {
                i++;
            }

            if (s[i] == '-' || s[i] == '+')
            {
                neg = s[i] == '-' ? -1 : 1;
                i++;
            }

            while (i < s.length() && (s[i] >= '0' && s[i] <= '9'))
            {

                ans = ans *10 + (s[i] - '0');
               	// ans *= 10;
                i++;
                if (ans * neg >= INT_MAX) return INT_MAX;
                if (ans * neg <= INT_MIN) return INT_MIN;
            }
            return ans * neg;
        }
};
