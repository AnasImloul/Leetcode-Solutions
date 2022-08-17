class Solution {
    public int reductionOperations(int[] nums) {
        Map<Integer, Integer> valMap = new TreeMap<>(Collections.reverseOrder());

        for (int i=0; i<nums.length; i++)
            valMap.put(nums[i], valMap.getOrDefault(nums[i], 0) + 1);

        int mapSize = valMap.size();
        int opsCount = 0;
        for (Map.Entry<Integer, Integer> entry : valMap.entrySet()) {
            opsCount += entry.getValue() * (--mapSize);
        }
        return opsCount;
    }
}
