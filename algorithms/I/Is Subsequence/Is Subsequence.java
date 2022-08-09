class Solution 
{
    public boolean isSubsequence(String s, String t) 
    {
        int i,x,p=-1;
        if(s.length()>t.length())
            return false;
        for(i=0;i<s.length();i++)
        {
            x=t.indexOf(s.charAt(i),p+1);
            if(x>p)
                p=x;
            else
                return false;
        }
        return true;
    }
}
