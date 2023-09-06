// Runtime: 14 ms (Top 91.4%) | Memory: 53.70 MB (Top 100.0%)

class Solution {
    public int countSubarrays(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int n = nums.length;
        int less = 0, great = 0;
        int pivot = -1;
        for(int i=0; i<n; ++i) {
            if(nums[i] == k) {
                pivot = i;
                break;
            }
        }
        
        for(int i=pivot; i<n; ++i) {
            if(nums[i] > k) great++;
            else if(nums[i] < k) less++;
            map.put(great-less, map.getOrDefault(great-less, 0)+1);
        }
        
        int count = 0;
        less=great=0;
        for(int i=pivot; i>=0; --i) {
            if(nums[i] > k) great++;
            else if(nums[i] < k) less++;
            int key = less-great;
            count += map.getOrDefault(key, 0) + map.getOrDefault(key+1, 0);
        }
        
        return count;
    }
}