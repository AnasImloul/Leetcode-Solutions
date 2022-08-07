
class Solution {

	public boolean isNumber(String s) {
	boolean hasSign = false;
	boolean hasExponent = false;
	int expIdx = -1;
	boolean hasDecimal = false;
	int decimalIdx = -1;
	boolean hasDigits = false;

	int idx = -1;
	while(++idx < s.length()) {
		char c = s.charAt(idx);
		if(c == '+' ||  c == '-') {
			//if it already has a sign but no exponent before another sign then invalid
			if(hasSign && !hasExponent) {return false;}
			//if it has an exponent but sign is not directly after the exponent
			if(hasExponent && idx != expIdx + 1) {return false;}
			//if its the first sign it has to be on index 0 and/or  directly after exponent
			if(!hasSign && !hasExponent && idx != 0) {return false;}
			hasSign = true;
		} else if(c == '.'){
			//if there was already another decimal then invalid
			if(hasDecimal) {return false;}
			hasDecimal = true;
			decimalIdx = idx;
			//if there was already another exponent then invalid
			if(expIdx != -1 && decimalIdx > expIdx) {
				return false;
			}
		} else if (c == 'e' || c == 'E') {
			//if there was already another exponent then invalid
			if(hasExponent) {return false;}
			hasExponent = true;
			//if there were no digits before exponent then invalid
			if(!hasDigits) {return false;}
			expIdx = idx;
			//if decimal value after exponent
			if(decimalIdx != -1 && decimalIdx > expIdx) {
				return false;
			}
		} else if(c >= '0' && c <= '9') {
			hasDigits = true;
		} else {
			//invalid char
			return false;
		}
	}

	//it has to have some digits
	if(!hasDigits) {return false;}

	//if it has a sign but sign is last char then invalid
	if(hasSign && (s.charAt(s.length() - 1) == '+' || s.charAt(s.length() - 1) == '-')) {return false;}

	//if it has a decimal and an exponent, then the value decimal value needs to be valid number (avoding ".e1", ".e", etc)
	if(hasDecimal && hasExponent && !((decimalIdx-1 >= 0 && (s.charAt(decimalIdx-1) >= '0' && s.charAt(decimalIdx - 1) <= '9')) || (s.charAt(decimalIdx+1) >= '0' && s.charAt(decimalIdx + 1) <= '9'))) {return false;}

	//exponent cannot be last char
	if(hasExponent && (expIdx == 0 || expIdx == s.length() - 1)) {
		return false;
	}

	return true;
}
}

