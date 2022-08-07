class Solution {
    public int singleNumber(int[] nums) {
        Stack numStack = new Stack();
        Arrays.sort(nums);
        for (var i = 0; i < nums.length; ++i) {
            numStack.push(nums[i]);
            if (i < nums.length - 1 && nums[++i] != (int) numStack.peek()) break;
        }
        return (int) numStack.pop();
    }
}
