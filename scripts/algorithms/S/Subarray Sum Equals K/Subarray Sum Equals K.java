// Runtime: 80 ms (Top 15.87%) | Memory: 68.2 MB (Top 25.50%)
/*
Runtime: 21 ms, faster than 98.97% of Java online submissions for Subarray Sum Equals K.
Memory Usage: 47.1 MB, less than 85.93% of Java online submissions for Subarray Sum Equals K.
*/
class Solution {
    public int subarraySum(int[] nums, int k) {

        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0,1);
        int count = 0;
        int sum = 0;

        for(int i=0; i<nums.length; i++){
            sum += nums[i];
            if(map.containsKey(sum - k)){
                count += map.get(sum-k);
            }
            map.put(sum, map.getOrDefault(sum,0)+1);
        }
        return count;
    }
}