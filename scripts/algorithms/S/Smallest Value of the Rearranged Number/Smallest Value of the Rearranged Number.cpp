// Runtime: 0 ms (Top 100.00%) | Memory: 6.1 MB (Top 63.28%)
class Solution
{
public:
    long long smallestNumber(long long num)
    {
        if (num < 0)
        {
            string s = to_string(-num);
            sort(s.rbegin(), s.rend());
            return -stoll(s);
        }
        else if (num == 0)
            return 0;
        string s = to_string(num);
        sort(s.begin(), s.end());
        int i = 0;
        while (s[i] == '0')
            i++;
        char c = s[i];
        s.erase(s.begin() + i);
        s = c + s;
        return stoll(s);
    }
};