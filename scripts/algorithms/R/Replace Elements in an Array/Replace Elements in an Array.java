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
