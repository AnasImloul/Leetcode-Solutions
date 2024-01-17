// Runtime: 3 ms (Top 73.74%) | Memory: 55.50 MB (Top 96.97%)

class Solution {
    public long numberOfWeeks(int[] milestones) {
        long sum = 0;
        int max = Integer.MIN_VALUE;
        for(int milestone: milestones) {
            sum += milestone;
            max = Math.max(milestone, max);
        }
        if((sum - max) < max)
            return ((sum - max) * 2) + 1;
        else
            return sum;
    }
}
