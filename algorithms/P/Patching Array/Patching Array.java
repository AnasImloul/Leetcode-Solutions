class Solution {
     public int minPatches(int[] nums, int n) {
        long sum = 0;
        int count = 0;
        for (int x : nums) {
            if (sum >= n) break;
            while (sum+1 < x && sum < n) { 
                ++count;
                sum += sum+1;
            }
            sum += x;
        }
        while (sum < n) {
            sum += sum+1;
            ++count;
        }
        return count;
    }
}
