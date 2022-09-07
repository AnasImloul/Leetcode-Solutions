// Runtime: 1 ms (Top 33.54%) | Memory: 45.2 MB (Top 7.46%)
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums.length == 0) return null;
        var mid = nums.length / 2;
        var root = new TreeNode(nums[mid]);
        var left_array = Arrays.copyOfRange(nums, 0, mid);
        var right_array = Arrays.copyOfRange(nums, mid + 1, nums.length);
        root.left = sortedArrayToBST(left_array);
        root.right = sortedArrayToBST(right_array);
        return root;
    }
}