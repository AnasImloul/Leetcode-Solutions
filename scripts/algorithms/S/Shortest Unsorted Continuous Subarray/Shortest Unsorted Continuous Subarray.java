// Runtime: 15 ms (Top 23.17%) | Memory: 53.7 MB (Top 75.07%)

class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] numsClone = nums.clone();
        Arrays.sort(nums);

        int s = Integer.MAX_VALUE;
        int e = Integer.MIN_VALUE;

        for(int i = 0; i<nums.length; i++) {
            if(numsClone[i] != nums[i]) {
                s = Math.min(s, i);
                e = Math.max(e, i);
            }
        }

        if(s == Integer.MAX_VALUE || e == Integer.MIN_VALUE) {
            return 0;
        }

        return e-s+1;
    }
}