class Solution 
{
    public boolean queryString(String s, int n) 
    {
        for(int i=1;i<=n;i++)
        {
            if(!(s.contains(toBinary(i))))
                return false;
        }
        return true;
    }
    public String toBinary(int n)
    {
        String binary="";
        while(n>0)
        {
            int r=n%2; //to find remainder
            binary=Integer.toString(r)+binary; //Last found remainder is MSB of Binary represantation. Hence, it is added first.
            n=n/2; //make the number ready for next iteration
        }
        return binary;
    }
}
