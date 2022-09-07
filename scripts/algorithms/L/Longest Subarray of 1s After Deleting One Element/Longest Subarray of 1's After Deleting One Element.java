// Runtime: 5 ms (Top 19.84%) | Memory: 58.6 MB (Top 26.14%)
class Solution {
    public int longestSubarray(int[] nums) {
        List<Integer> groups = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0)
                groups.add(nums[i]);
            if (nums[i] == 1) {
                int count = 0;
                while (i < nums.length && nums[i] == 1) {
                    count++;
                    i++;
                }
                groups.add(count);
                if (i < nums.length && nums[i] == 0)
                    groups.add(0);
            }
        }
        int max = 0;
        if (groups.size() == 1) {
            return groups.get(0) - 1;
        }
        for (int i = 0; i < groups.size(); i++) {
            if (i < groups.size() - 2) {
                max = Math.max(max, groups.get(i) + groups.get(i+2));
            } else {
                max = Math.max(max, groups.get(i));
            }
        }

        return max;
    }
}