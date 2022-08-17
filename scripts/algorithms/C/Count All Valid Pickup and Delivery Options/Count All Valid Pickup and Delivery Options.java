class Solution {
    public int countOrders(int n) {
        int mod = 1000000007;
        long ans = 1, sum = 0;
        for(int i=0;i<n;i++){
            sum += (4*i+1);
            ans = (ans*sum)%mod;
        }
        return (int)(ans%mod);
    }
}
