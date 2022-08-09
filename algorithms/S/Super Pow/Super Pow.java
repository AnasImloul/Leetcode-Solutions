import java.math.BigInteger;
class Solution {
    public int superPow(int a, int[] b) {
        StringBuilder bigNum = new StringBuilder();
        Arrays.stream(b).forEach(i -> bigNum.append(i));
        
        return 
            BigInteger.valueOf(a)
            .modPow(new BigInteger(bigNum.toString()), BigInteger.valueOf(1337))
            .intValue();
    }
}
