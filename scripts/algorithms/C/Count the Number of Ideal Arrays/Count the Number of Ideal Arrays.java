
class Solution {
    int M =(int)1e9+7;
    public int idealArrays(int n, int maxValue) {
        long ans = 0;
        int N = n+maxValue;
        long[] inv = new long[N];
        long[] fact = new long[N];
        long[] factinv = new long[N];
        inv[1]=fact[0]=fact[1]=factinv[0]=factinv[1]=1;
        for (int i = 2; i < N; i++){ // mod inverse
            inv[i]=M-M/i*inv[M%i]%M;
            fact[i]=fact[i-1]*i%M;
            factinv[i]=factinv[i-1]*inv[i]%M;
        }
        for (int i = 1; i <= maxValue; i++){
            int tmp = i;
            Map<Integer, Integer> map = new HashMap<>();
            for (int j = 2; j*j<= tmp; j++){
                while(tmp%j==0){  // prime factorization.
                    tmp/=j;
                    map.merge(j, 1, Integer::sum);
                }
            }
            if (tmp>1){
                map.merge(tmp, 1, Integer::sum);
            }
            long gain=1;
            for (int val : map.values()){ // arranges all the primes.
                gain *= comb(n+val-1, val, fact, factinv);
                gain %= M;
            }
            ans += gain;
            ans %= M;
        }

        return (int)ans;
    }

    private long comb(int a, int b, long[] fact, long[] factinv){
        return fact[a]*factinv[b]%M*factinv[a-b]%M;
    }
}
