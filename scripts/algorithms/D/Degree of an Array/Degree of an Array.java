class Solution {
    public int findShortestSubArray(int[] nums) {
       int ans = Integer.MAX_VALUE;
        Map<Integer, Integer> count = new HashMap<>();
        Map<Integer, Integer> startIndex = new HashMap<>();
        Map<Integer, Integer> endIndex = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            count.put(nums[i], count.getOrDefault(nums[i], 0) + 1);
        }

        for (int i = 0; i < nums.length; i++) {
            int no = nums[i];
            if (!startIndex.containsKey(no)) {
                startIndex.put(no, i);
            }
            endIndex.put(no, i);
        }

        int degree = Integer.MIN_VALUE;
        for (Integer key : count.keySet()) {
            degree = Math.max(degree, count.get(key));
        }

        for (Integer key : count.keySet()) {
            if (count.get(key) == degree) {
                int arraySize = endIndex.get(key) - startIndex.get(key) + 1;
                ans = Math.min(ans, arraySize);
            }
        }

        return ans; 
    }
}
