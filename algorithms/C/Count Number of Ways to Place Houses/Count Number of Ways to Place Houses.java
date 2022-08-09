class Solution {
    int mod = (int)1e9+7;
    public int countHousePlacements(int n) {
        
        if(n == 1)
            return 4;
        if(n == 2)
            return 9;
        long a = 2;
        long b = 3;
        if(n==1)
            return (int)(a%mod);
        if(n==2)
            return (int)(b%mod);
        long c=0;
        for(int i=3;i<=n;i++)
        {
            c = (a+b)%mod;
            a=b%mod;
            b=c%mod;
        }
        
        return (int)((c*c)%mod);
    }
}
