// Runtime: 0 ms (Top 100.0%) | Memory: 40.41 MB (Top 54.8%)

class Solution 
{
    public int numSteps(String s)
    {
        int countSteps = 0;
        int carry = 0;
        for(int i = s.length()-1;i>=1;i--)
        {
            int rightMostBit = s.charAt(i)-'0';
            if((rightMostBit+carry) == 1)
            {
                carry=1;
                countSteps += 2;
            }
            else
            {
                countSteps++;
            }
        }
        return countSteps+carry;
    }
} 