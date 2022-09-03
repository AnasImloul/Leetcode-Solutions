// Runtime: 2 ms (Top 82.01%) | Memory: 50 MB (Top 21.41%)
class Solution {

    public int jump(int[] nums) {

        int result = 0;

        int L = 0;
        int R = 0;

        while (R < nums.length - 1) {

            int localMaxRight = 0;

            for (int i=L; i<=R; i++) {

                localMaxRight = Math.max(i + nums[i], localMaxRight);
            }

            L = R + 1;
            R = localMaxRight;
            result++;
        }

        return result;
    }
}