class Solution {
    public int[] decompressRLElist(int[] nums) {
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i+1 < nums.length; i += 2) {
            for (int j = 0; j < nums[i]; ++j) {
                arr.add(nums[i+1]);
            }
        }
        int[] res = new int[arr.size()];
        for (int i = 0; i < res.length; ++i) res[i] = arr.get(i);
        return res;
    }
}
