// Runtime: 0 ms (Top 100.00%) | Memory: 40.5 MB (Top 96.61%)
class Solution {
    public int[] plusOne(int[] digits) {

        int len = digits.length;

        //last digit not a 9, just add 1 to it
        if(digits[len - 1] != 9){
            digits[len - 1] = digits[len - 1] + 1;
            return digits;
        }

        //last digit is a 9, find the closest digit that is not a 9
        else{
            int i = len - 1;
            while(i >= 0 && digits[i] == 9){
                digits[i] = 0;
                i--;
            }
            if(i == -1){
                int[] ret = new int[len + 1];
                for(int j = 0; j < len; j++){
                    ret[j+1] = digits[j];
                }
                ret[0] = 1;
                return ret;
            }
            digits[i] = digits[i] + 1;
        }

        return digits;
    }
}