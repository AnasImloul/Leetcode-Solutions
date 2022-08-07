class Solution {

  public void sortColors(int[] nums) {

    int zeroIndex = 0, twoIndex = nums.length - 1, i = 0;
    while (i <= twoIndex) {
      if (nums[i] == 0)
        swap(nums, zeroIndex++, i++);
      else if (nums[i] == 2)
        swap(nums, twoIndex--, i);
      else
        i++;
    }
  }

  public void swap(int[] nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
}