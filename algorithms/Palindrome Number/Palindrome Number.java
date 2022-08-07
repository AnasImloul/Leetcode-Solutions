class Solution {
    public boolean isPalindrome(int x)
    {
        if(x<0)
        {
            return false;
        }
        int sol = rev(x);
        return sol==x;


    }
    int rev(int number)
    {
        int result= 0;
        while(number != 0)
        {
            int remainder = number % 10;
            result = result * 10 + remainder;
            number = number/10;
        }
        return result;


    }
}