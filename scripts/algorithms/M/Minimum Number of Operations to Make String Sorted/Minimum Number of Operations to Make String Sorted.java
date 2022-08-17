import java.math.*;

class Solution {
    public int makeStringSorted(String s) {
        BigInteger res = new BigInteger("0");
        BigInteger mod = new BigInteger("1000000007");
        
        int[] count = new int[26];
        BigInteger[] fact = factory(s.length(), mod);
        
        int n = s.length();
        BigInteger div = new BigInteger("1");
                
        for (int i = n - 1; i >= 0; --i) {
            char c = s.charAt(i);
            count[c-'a'] ++;
            BigInteger c1 = countInverse(count, c);            
            BigInteger ans = c1.multiply(fact[n-i-1]);
            div = div.multiply(new BigInteger(String.valueOf(count[c-'a'])));
            ans = ans.multiply(div.modPow(mod.subtract(new BigInteger(String.valueOf(2))), mod)).mod(mod);
            res = res.add(ans).mod(mod);
        }
        
        return res.intValue();
    }
    
    public BigInteger countInverse(int[] count, char c) {
        long cnt = 0;
        for (int i = 0; i < (c - 'a'); ++i) {
            cnt += count[i];
        }
        
        return new BigInteger(String.valueOf(cnt));
    }
    
    public BigInteger[] factory(int n, BigInteger mod) {
        BigInteger[] fact = new BigInteger[n+1];
        fact[0] = new BigInteger("1");
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i-1].multiply(new BigInteger(String.valueOf(i))).mod(mod);
        }
        
        return fact;
    }
}
