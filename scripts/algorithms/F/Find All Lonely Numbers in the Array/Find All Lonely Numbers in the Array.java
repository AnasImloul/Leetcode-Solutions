class Solution {
    public List<Integer> findLonely(int[] nums) {
        Arrays.sort(nums);
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 1; i < nums.length - 1; i++) {
            if (nums[i - 1] + 1 < nums[i] && nums[i] + 1 < nums[i + 1]) {
                list.add(nums[i]);
            }
        }
        if (nums.length == 1) {
            list.add(nums[0]);
        }
        if (nums.length > 1) {
            if (nums[0] + 1 < nums[1]) {
                list.add(nums[0]);
            }
            if (nums[nums.length - 2] + 1 < nums[nums.length - 1]) {
                list.add(nums[nums.length - 1]);
            }
        }
        return list;
    }
}
