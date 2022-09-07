// Runtime: 7 ms (Top 11.82%) | Memory: 74.9 MB (Top 84.55%)
class Solution {
    public int minElements(int[] nums, int limit, int goal) {
        long sum = 0;
        for(int num: nums)
            sum += num;
        long diff = Math.abs(sum-goal);
        return (int) (diff/limit) + (diff%limit>0?1:0);
    }
}