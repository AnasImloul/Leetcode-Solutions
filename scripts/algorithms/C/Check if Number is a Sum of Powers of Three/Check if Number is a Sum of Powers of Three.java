// Runtime: 1 ms (Top 41.31%) | Memory: 41.4 MB (Top 27.03%)

class Solution {
    public boolean checkPowersOfThree(int n) {
        //max power of 3
        int maxPower = (int)(Math.log(n) / Math.log(3));

        //save all the power of 3 from 0 to maxPower
        // 3^0, 3^1, 3^2 .... 3^maxPower
        int[] threePower = new int[maxPower + 1];
        threePower[0] = 1;
        for(int i = 1; i <= maxPower; i++){
            threePower[i] = threePower[i - 1] * 3;
        }

        //Intuition
        //if we subtract n with every power of 3
        //at the end if n is zero, then it is sum of power 3

        //subtract n with power of 3,
        //if n is graeter than power
        for(int i = maxPower; i >= 0; i--){
            //n is greater/equal to power 3
            if(n >= threePower[i]){
                 n -= threePower[i];
            }
        }

        return n == 0;
    }
}