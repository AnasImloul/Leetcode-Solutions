class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        // nums all equals to zero
        int[] nums = new int[n];
        // construct the diffs
        Difference df = new Difference(nums);

        for (int[] booking : bookings) {
            // pay attention to the index
            int i = booking[0] - 1;
            int j = booking[1] - 1;
            int val = booking[2];
            // increase nums[i..j] by val
            df.increment(i, j, val);
        }
        // return the final array
        return df.result();
    }

    class Difference {
        // diff array
        private int[] diff;

        public Difference(int[] nums) {
            assert nums.length > 0;
            diff = new int[nums.length];
            // construct the diffs
            diff[0] = nums[0];
            for (int i = 1; i < nums.length; i++) {
                diff[i] = nums[i] - nums[i - 1];
            }
        }

        // increase nums[i..j] by val
        public void increment(int i, int j, int val) {
            diff[i] += val;
            if (j + 1 < diff.length) {
                diff[j + 1] -= val;
            }
        }

        public int[] result() {
            int[] res = new int[diff.length];
            // contract the diff array based on the result
            res[0] = diff[0];
            for (int i = 1; i < diff.length; i++) {
                res[i] = res[i - 1] + diff[i];
            }
            return res;
        }
    }

}
