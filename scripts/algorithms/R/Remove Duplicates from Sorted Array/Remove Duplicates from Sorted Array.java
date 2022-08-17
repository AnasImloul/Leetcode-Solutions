class Solution {
    public int removeDuplicates(int[] nums) {
        int ptr = 0;
        int arr[] = new int[nums.length];
        arr[0] = nums[0];
        for(int i=1;i<nums.length;i++) {
            if (arr[ptr] != nums[i]) {
                arr[ptr + 1] = nums[i];
                ptr++;
            }
        }
        for(int i=0;i<arr.length;i++) {
            nums[i] = arr[i];
        }
        return ptr+1;
    }
}
