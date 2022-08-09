class Solution {
    public int myAtoi(String s) {
        long n=0;
        int i=0,a=0;
        s=s.trim();
        if(s.length()==0)
            return 0;
        if(s.charAt(i)=='+' || s.charAt(i)=='-')
            a=1;
        while(a<s.length())
            if(s.charAt(a)=='0')
                a++;
            else 
                break;
        for(i=a;i<a+11 && i<s.length();i++)
        {
            if(s.charAt(i)>='0' && s.charAt(i)<='9')
                n=n*10+(int)(s.charAt(i)-'0');
            else
                break;
        }
        if(s.charAt(0)=='-')
            n=-n;
        if(n>2147483647)
            n=2147483647;
        if(n<-2147483648)
            n=-2147483648;
        return (int)n;
    }
}
