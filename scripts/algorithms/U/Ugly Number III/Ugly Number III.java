class Solution {
    public int nthUglyNumber(int n, int a, int b, int c) {
        int low = 1, high =2*(int)1e9;
        
        int ab = lcm(a,b), bc = lcm(b,c), ca = lcm(c,a), abc = lcm(a,bc);
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            int count = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ca + mid/abc;
            if(count>=n){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
    private int lcm(int x,int y){
        int a = x, b = y; 
        while(a!=0){
            int t = a;
            a = b%a;
            b = t;
        }
        int ans = 0;
        try{
            ans = (x>y) ? Math.multiplyExact(y,(x/b)) : Math.multiplyExact(x,(y/b));  // x*y/gcd(x,y)
        }catch(Exception e){
            ans = Integer.MAX_VALUE;
        }
        return ans;
    }
}
