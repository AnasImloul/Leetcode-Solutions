class Solution
{
    public int minimumNumbers(int num, int k)
    {
        if(num == 0)
            return 0;
        if(k == 0)
            if(num % 10 == 0) //E.g. 20,1590,3000
                return 1;
            else
                return -1;
        for(int i = 1; i <= num/k; i++) // Start with set size 1 and look for set having unit's digit equal to that of num
            if(num % 10 == ((i*k)%10)) // Look for equal unit's digit
                return i;
        
        return -1;
    }
}
