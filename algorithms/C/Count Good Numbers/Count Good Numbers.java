class Solution {
    int mod=(int)1e9+7;
    public int countGoodNumbers(long n) {
        long first=(n%2==0?(n/2):(n/2)+1);//deciding n/2 or n/2+1 depending on n is even or odd
        long second=n/2;//second power would be n/2 only irrespective of even or odd
        long mul1=power(5,first)%mod;//5 power n/2
        long mul2=power(4,second)%mod;//4 power n/2
        long ans=1;
        ans=(ans*mul1)%mod;//computing total product
        ans=(second!=0)?(ans*mul2)%mod:ans;//computing total product
        return (int)(ans%mod);
    }
    public long power(long x,long y){// this method computes pow(x,y) in O(logn) using divide & conquer
        long temp;
        if(y==0) return 1;//base case (x power 0 = 1)
        temp=power(x,y/2);//computing power for pow(x,y/2) -> divide & conquer step
        if(y%2==0) return (temp*temp)%mod; //using that result of subproblem (2 power 2 = 2 power 1 * 2 power 1)
        else return (x*temp*temp)%mod;//using that result of subproblem (2 power 3 = 2 power 1 * 2 power 1 * 2)
		// if y is odd, x power y = x power y/2 * x power y/2 * x
		// if y is even, x power y = x power y/2 * x power y/2
    }
}
