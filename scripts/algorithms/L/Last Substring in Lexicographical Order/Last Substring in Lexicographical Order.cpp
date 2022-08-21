// Runtime: 63 ms (Top 63.10%) | Memory: 18.5 MB (Top 16.07%)

class Solution
{
    public:
        string lastSubstring(string s)
        {
            int maxIndex = s.length() - 1;

            for (int currIndex = s.length() - 1; currIndex >= 0; currIndex--)
            {
                if (s[currIndex] > s[maxIndex])
                    maxIndex = currIndex;

                else if (s[currIndex] == s[maxIndex])
                {
                    int i = currIndex + 1;
                    int j = maxIndex + 1;

                    while (i < maxIndex && j < s.length() && s[i] == s[j])
                    {
                        i++;
                        j++;
                    }

                    if (i == maxIndex || j == s.length() || s[i] > s[j])
                        maxIndex = currIndex;
                }
            }

            return s.substr(maxIndex);
        }
};