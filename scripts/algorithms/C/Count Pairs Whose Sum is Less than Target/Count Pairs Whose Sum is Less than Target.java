// Runtime: 3 ms (Top 26.3%) | Memory: 40.75 MB (Top 94.5%)

class Solution {
    public int countPairs(List<Integer> nums, int target) {
      int n = nums.size();

      // Sort the List.
      Collections.sort(nums);

      // Initialize the number of pairs.
      int countPairs = 0;

      // Initialize the left and right pointers.
      int low = 0;
      int high = n - 1;

      // Iterate while the left pointer is less than the right pointer.
      while (low < high) {
        // Calculate the sum of the two elements.
        int sum = nums.get(low) + nums.get(high);

        // If the sum is less than the target, then increment the number of pairs.
        if (sum < target) {
          countPairs += high - low;
          low++;
        } else {
          // Otherwise, decrement the right pointer.
          high--;
        }
      }

      // Return the number of pairs.
      return countPairs;
    }
}

