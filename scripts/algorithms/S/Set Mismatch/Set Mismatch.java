class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int dup = 0, miss = 0;

        for (int i = 1; i <= n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) count++;
            }

            if (count == 2) dup = i;
            if (count == 0) miss = i;
        }

        return new int[] {dup, miss};
    }
}

// TC: O(n ^ 2), SC: O(1)