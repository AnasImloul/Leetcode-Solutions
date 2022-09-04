// Runtime: 105 ms (Top 5.11%) | Memory: 85 MB (Top 62.04%)
class Solution {
    public int maxNonOverlapping(int[] nums, int target) {
        Map<Integer, Integer> valToPos = new HashMap<>();
        int sums = 0;
        int count = 0;
        int lastEndPos = 0;
        valToPos.put(0, 0);
        for (int i = 0; i < nums.length; i++) {
            sums += nums[i];
            int pos = valToPos.getOrDefault(sums - target, -1);
            if (pos >= lastEndPos) {
                count += 1;
                lastEndPos = i + 1;
            }
            valToPos.put(sums, i + 1);
        }
        return count;
    }
}