// Runtime: 100 ms (Top 96.09%) | Memory: 44.90 MB (Top 25.98%)

class Solution {
    private int binarySearch(int[] nums, int target) {
        int i = 0;
        int j = nums.length;
        while(i < j) {
            int mid = i + (j - i) / 2;
            if(nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        return i;
    }
    public int maxDivScore(int[] nums, int[] divisors) {
        Arrays.sort(nums);
        int max = 0;
        int res = divisors[0];
        for(int d : divisors) {
            int score = 0;
            for(int i = binarySearch(nums, d); i < nums.length; ++i) {
                if( nums[i] % d == 0) {
                    ++score;
                }
            }
            if(score > max) {
                max = score;
                res = d;
            } else if (score == max) {
                res = Math.min(res, d);
            }
        }
        return res;
    }
}
