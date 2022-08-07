import java.math.BigInteger;
class Solution {
	public String addStrings(String num1, String num2) {
		return new BigInteger(num1).add(new BigInteger(num2)).toString();        
	}
}
