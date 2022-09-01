// Runtime: 127 ms (Top 67.88%) | Memory: 81.5 MB (Top 9.11%)
class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        if (nums.length % k != 0) return false;
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int num : nums) {
            int count = countMap.getOrDefault(num, 0);
            countMap.put(num , count + 1);
        }
        Arrays.sort(nums);
        for (int num : nums) {
            if (!countMap.containsKey(num)) continue;
            int count = countMap.get(num);
            if (count == 1) countMap.remove(num);
            else countMap.put(num, count - 1);
            for (int i = 1; i < k; i++) {
                int next = num + i;
                if (!countMap.containsKey(next)) return false;
                count = countMap.get(next);
                if (count == 1) countMap.remove(next);
                else countMap.put(next, count - 1);
            }
        }
        return true;
    }
}