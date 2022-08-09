class Solution {
    public long[] kthPalindrome(int[] queries, int intLength) {
        long[] res= new long[queries.length];
        for(int i=0;i<queries.length;i++){
            res[i]=nthPalindrome(queries[i],intLength);
        }
        return res;
    }
    public long nthPalindrome(int nth, int kdigit)
    {
    long temp = (kdigit & 1)!=0 ? (kdigit / 2) : (kdigit/2 - 1);
    long palindrome = (long)Math.pow(10, temp);
    palindrome += nth - 1;
    long res1=palindrome;
    if ((kdigit & 1)>0)
        palindrome /= 10;
    while (palindrome>0)
    {
        res1=res1*10+(palindrome % 10);
        palindrome /= 10;
    }
    String g="";
    g+=res1;
    if(g.length()!=kdigit)
        return -1;
    return res1;
}
}
