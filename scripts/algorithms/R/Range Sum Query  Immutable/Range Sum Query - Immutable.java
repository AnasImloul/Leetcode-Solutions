// Runtime: 19 ms (Top 40.96%) | Memory: 48.9 MB (Top 68.21%)
class NumArray {
    int [] prefix;
    public NumArray(int[] nums) {
        int n = nums.length;
        prefix = new int[n];
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = nums[i] + prefix[i - 1];
        }
    }

    public int sumRange(int left, int right) {
        if(left == 0){
            return prefix[right];
        }
        return prefix[right] - prefix[left - 1];
    }
}