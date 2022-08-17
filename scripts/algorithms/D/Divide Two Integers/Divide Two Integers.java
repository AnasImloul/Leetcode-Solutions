class Solution {
    public int divide(int dividend, int divisor) {
        if(dividend==Integer.MIN_VALUE && divisor==-1) return Integer.MAX_VALUE;
        int sign = (dividend>=0) ^ (divisor>=0) ? -1:1;
        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);
        int res=0;
        while (dividend-divisor>=0){
            int x=0;
            while (dividend - (divisor<<1<<x) >=0) x++;
            res+=(1<<x);
            dividend-=(divisor<<x);
        }
        return res*sign;
    }
}
