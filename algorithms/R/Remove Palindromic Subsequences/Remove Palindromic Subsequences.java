class Solution 
{
    public int removePalindromeSub(String s) 
    {
        int left = 0 , right = s.length() - 1 ;       
        while( left < right )
        {
            if( s.charAt(left++) != s.charAt(right--) )
            {
                return 2 ;
            }
        }
        return 1 ;
    }
}
