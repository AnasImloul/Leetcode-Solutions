class Solution {
    public int integerReplacement(int n) {
        return (int)calc(n,0);
    }
    public long calc(long n,int i){
        if(n==1) 
            return i;
        if(n<1) 
            return 0;
        
        long a=Long.MAX_VALUE,b=Long.MAX_VALUE,c=Long.MAX_VALUE;
        
        if(n%2==0) 
            a=calc(n/2,i+1);
        else{
            b=calc(n-1,i+1);
            c=calc(n+1,i+1);
        }
        long d=Math.min(a,Math.min(b,c));
        return d;
    }
}
