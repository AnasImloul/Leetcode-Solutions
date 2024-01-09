// Runtime: 4 ms (Top 94.57%) | Memory: 6.30 MB (Top 51.12%)

class Solution {
public:
    bool isPowerOfThree(int n)
    {
        if(n < 1)
        {
            return false;
        }
        if(n == 1)
        {
            return true;
        }
        if(n%3 != 0)
        {
            return false;
        }
        return isPowerOfThree(n/3);
    }
};
