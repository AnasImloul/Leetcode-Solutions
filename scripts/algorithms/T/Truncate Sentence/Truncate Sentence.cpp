// Runtime: 0 ms (Top 100.00%) | Memory: 6.5 MB (Top 20.23%)
class Solution
{
public:
    string truncateSentence(string s, int k)
    {
        string resStr = "";
        int words = 0;

        for ( char i : s ) {
            if ( i == ' ')
                words++;
            if ( words < k )
                resStr += i;
        }

        return resStr;
    }
};