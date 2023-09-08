// Runtime: 16 ms (Top 46.1%) | Memory: 40.11 MB (Top 41.3%)

class Solution {
    public boolean circularArrayLoop(int[] nums) {
        for (int i=0; i<nums.length; i++) {
            boolean isForward = nums[i] > 0;
            int slow = i;
            int fast = i; 
            do {
                slow = findNextIndex(nums, isForward, slow);
                fast = findNextIndex(nums, isForward, fast);
                if (fast != -1) {
                    fast = findNextIndex(nums, isForward, fast);
                }
            } while (slow != -1 && fast != -1 && slow != fast);
            if (slow != -1 && slow == fast) {
                return true;
            }
        }
        return false;
    }
    private int findNextIndex(int[] arr, boolean isForward, int currentIndex) {
        boolean direction = arr[currentIndex] >= 0;
        if (isForward != direction) {
            return -1;
        }
        int nextIndex = (currentIndex + arr[currentIndex]) % arr.length;
        if (nextIndex < 0) {
            nextIndex += arr.length;
        }
        if (nextIndex == currentIndex) {
            nextIndex = -1;
        }
        return nextIndex;
    }
}