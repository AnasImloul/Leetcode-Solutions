class Solution
{
    public int countEven(int num)
    {
        int count = 0;
        for(int i = 1; i <= num; i++)
            if(sumDig(i))
                count++;
        return count;
    }
    private boolean sumDig(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
		return (sum&1) == 0 ? true : false;
    }
}
