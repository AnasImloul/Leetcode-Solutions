class Solution {
    public String subStrHash(String s, int power, int modulo, int k, int hashValue) {
		// calculate all the powers from power^0 till power^k
		// utilized binary exponentiation
		long[] powers = new long[k];
        for (int i = 0; i < k; i++) 
            powers[i] = binaryExponentiation(power, i, modulo);
        
		// pre compute the initial hash from behind.
		// I have explained at top you why traversing from behind is easy
        long currentHashValue = 0;
        int index = s.length() - 1;
        int powerIndex = k-1;
        while (index >= s.length() - k) {
			// (a+b) % modulo = ( (a % modulo) + (b % modulo) ) % modulo;
			// do it for k times from behind
            currentHashValue += ((s.charAt(index--) - 'a' + 1) % modulo * powers[powerIndex--] % modulo) % modulo;
        }
        currentHashValue %= modulo;
        
        int startIndex = 0;
        if (currentHashValue == hashValue) {
            startIndex = s.length() - k;
        }
        
		// I have pre computed already for k values from behind. so start from (length of S - k - 1)
		// Let's take an example of "leetcode" itself
		// "de" is pre computed
		// point is to add one character from behind and remove one from end (Sliding from back to first)
		// Modular Arithmetic for (a-b) % modulo = ( (a % modulo) - (b % modulo) + modulo) % modulo;
		// keep tracking of the start index if hash value matches. That's it.
        for (int i = s.length() - k - 1; i >= 0; i--) {
			// below line a --> currentHashValue 
			// below line b --> (s.charAt(i+k) - 'a' + 1 * powers[k-1])
            currentHashValue = ((currentHashValue % modulo) - (((s.charAt(i+k) - 'a' + 1) * powers[k-1]) % modulo) + modulo) % modulo;
			// we need to multiply a power once for all
			// MULTIPLICATION
            currentHashValue = currentHashValue * power;
			// Modular Arithmetic for (a+b) % modulo is below line
            currentHashValue = (currentHashValue % modulo + (s.charAt(i) - 'a' + 1) % modulo) % modulo;
            
            if (currentHashValue == hashValue) {
                startIndex = i;
            }
        }
        return s.substring(startIndex, startIndex+k);
    }
    
    private long binaryExponentiation(long a, long b, long mod) {
        a %= mod;
        long result = 1;
        while (b > 0) {
            if (b % 2 == 1)
                result = result * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return result;
    }
}
