// Runtime: 11 ms (Top 68.46%) | Memory: 54.3 MB (Top 56.38%)

class Solution {

    public int maxSumDivThree(int[] nums) {
        int r0 = 0;
        int r1 = 0;
        int r2 = 0;
        for (int i = 0; i < nums.length; i++) {
            int nr0 = r0;
            int nr1 = r1;
            int nr2 = r2;
            int a = r0 + nums[i];
            int b = r1 + nums[i];
            int c = r2 + nums[i];
            if (a % 3 == 0) {
                nr0 = Math.max(nr0, a);
            } else if (a % 3 == 1) {
                nr1 = Math.max(nr1, a);
            } else if (a % 3 == 2) {
                nr2 = Math.max(nr2, a);
            }

            if (b % 3 == 0) {
                nr0 = Math.max(nr0, b);
            } else if (b % 3 == 1) {
                nr1 = Math.max(nr1, b);
            } else if (b % 3 == 2) {
                nr2 = Math.max(nr2, b);
            }

            if (c % 3 == 0) {
                nr0 = Math.max(nr0, c);
            } else if (c % 3 == 1) {
                nr1 = Math.max(nr1, c);
            } else if (c % 3 == 2) {
                nr2 = Math.max(nr2, c);
            }
            r0=nr0;
            r1=nr1;
            r2=nr2;
        }

        return r0;
    }
}