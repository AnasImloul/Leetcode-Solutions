// Runtime: 136 ms (Top 26.4%) | Memory: 44.16 MB (Top 70.9%)

class Solution {
	private int mod = 1000000007;
    //100 digits in a number 10 ^ 100

    // 2nd dimesion is for whether you passed a digit equal to the digit in the same index upper bound of range which is numStr->> if yes -- then you are bounded other wise you can take any digit after it as per your choice
    
    //3rd dimension is for whether the previous digits include before current digit to be considered to be included are zero or not ? if yes then you can take any digit of your choice, if no then you can only take those digits whose absoulte difference with previous digit included is one
    
    //4th dimesnion is for how many options are you having to fill the current position-- if there are no constraints there are 0 to 9 i.e. 10 options available only  
    private Integer stepCount[][][][] = null;
    public int countSteppingNumbers(String low, String high) {
     	stepCount = new Integer[101][2][2][10];
        int left = countStepNums(low, 0, 1, 1, 0);
        
     	stepCount = new Integer[101][2][2][10];
        int right = countStepNums(high, 0, 1, 1, 0);
        
        int answer = (right % mod - left % mod + mod) % mod;
        
        boolean incLow = true;
        for (int indx = 0; indx < low.length(); indx++){
            if (indx != 0 && Math.abs(low.charAt(indx) - low.charAt(indx - 1)) != 1) incLow = false;
        }
        if (incLow) answer = (answer + 1) % mod;

        return (int)answer;
    }
    private int countStepNums(String numStr, int numIndx, int isBounded,
     int arePrevZeroes, int prevDigs) {
        if (numIndx == (int) numStr.length()) {
            return (arePrevZeroes == 1) ? 0 : 1;
        }

        if (stepCount[numIndx][isBounded][arePrevZeroes][prevDigs] != null) return stepCount[numIndx][isBounded][arePrevZeroes][prevDigs];

        int answer = 0, willBeZero = -1, newisBounded = -1;
        int limit =(isBounded == 1) ? (numStr.charAt(numIndx) - '0') :  9;

        for (int dig = 0; dig <= limit; dig++) {
            willBeZero = (arePrevZeroes == 1 && dig == 0) ? 1 :  0;
            newisBounded = (isBounded == 1 && dig == limit) ? 1 : 0;
            
            if (arePrevZeroes == 1 || Math.abs(dig - prevDigs) == 1) {
                answer = (answer % mod + countStepNums(numStr, numIndx + 1, newisBounded, willBeZero, dig) % mod)%mod;
            }
        }

        stepCount[numIndx][isBounded][arePrevZeroes][prevDigs] = answer;
        return answer;
    }
    
}