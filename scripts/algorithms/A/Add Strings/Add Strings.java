// Runtime: 19 ms (Top 29.95%) | Memory: 42.8 MB (Top 82.92%)
import java.math.BigInteger;
class Solution {
    public String addStrings(String num1, String num2) {
        return new BigInteger(num1).add(new BigInteger(num2)).toString();
    }
}