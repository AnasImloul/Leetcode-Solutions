class Solution
{
    public long numberOfWays(String s)
    {
        int zero = 0; // Individual zeroes count
        long zeroOne = 0; // Number of combinations of 01s
        int one = 0; // Individual ones count
        long oneZero = 0; // Number of combinations of 10s
        long tot = 0; // Final answer
        for(char ch : s.toCharArray())
        {
            if(ch == '0')
            {
                zero++;
                if(one > 0)
                    oneZero += one; // Each of the previously found 1s can pair up with the current 0 to form 10
                if(zeroOne > 0)
                    tot += zeroOne; // Each of the previously formed 01 can form a triplet with the current 0 to form 010
            }
            else
            {
                one++;
                if(zero > 0)
                    zeroOne += zero; // Each of the previously found 0s can pair to form 01
                if(oneZero > 0)
                    tot += oneZero; // Each of the previously formed 10 can form 101
            }
        }
        return tot;
    }
}
