// Runtime: 313 ms (Top 34.84%) | Memory: 43.9 MB (Top 52.81%)
class Solution {
    public boolean isPalindrome(String s) {
        if(s.length()==1 || s.length()==0)
        {
            return true;
        }

        s=s.trim().toLowerCase();
        //s=s.toLowerCase();
        String a="";
        boolean bool=false;
        for(int i=0;i<s.length();i++)
        {
            if((s.charAt(i)>='a' && s.charAt(i)<='z') || (s.charAt(i)>='0' && s.charAt(i)<='9'))
            {
                a=a+s.charAt(i);
            }
        }
        if(a.length()==1 || a.length()==0)
        {
            return true;
        }
        for(int i=0;i<a.length()/2;i++)
        {
            if(a.charAt(i)==a.charAt(a.length()-i-1))
            {
                bool=true;
            }
            else{
                return false;
            }
        }

        return bool;
    }
}