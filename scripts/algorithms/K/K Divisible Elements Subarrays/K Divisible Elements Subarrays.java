// Runtime: 99 ms (Top 84.38%) | Memory: 67.2 MB (Top 74.81%)
class Solution {
    public int countDistinct(int[] nums, int k, int p) {
        int n = nums.length;
        // we are storing hashcode for all the substrings so that we can compare them faster.
        // main goal is to avoid entire sub array comparision using hashcode.
        Set<Long> ways = new HashSet<>();
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            long hc = 1; // this is the running hashcode for sub array [i...j]
            for(int j = i; j < n; j++) {
                hc = 199L * hc + nums[j]; // updating running hashcode, since we nums are <=200, we shall consider a prime near 200 to avoid collision
                if(nums[j] % p == 0)
                    cnt++;
                if(cnt <= k) { // if current subarray [i...j] is valid, add its hashcode in our storage.
                    ways.add(hc);
                }
            }
        }
        return ways.size();
    }
}