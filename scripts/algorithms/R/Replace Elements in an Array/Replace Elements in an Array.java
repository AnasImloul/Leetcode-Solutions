// Runtime: 124 ms (Top 26.09%) | Memory: 164.1 MB (Top 72.68%)
class Solution {
    public int[] arrayChange(int[] nums, int[][] operations) {
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<nums.length;i++) map.put(nums[i],i);
        for(int[] op: operations) {
            nums[map.get(op[0])] = op[1];
            map.put(op[1],map.get(op[0]));
            map.remove(op[0]);
        }
        return nums;
    }
}