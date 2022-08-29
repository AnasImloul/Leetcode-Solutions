// Runtime: 44 ms (Top 94.02%) | Memory: 55.7 MB (Top 95.47%)
class Solution {
    public long countBadPairs(int[] nums) {
        HashMap<Integer, Integer> seen = new HashMap<>();
        long count = 0;
        for(int i = 0; i < nums.length; i++){
            int diff = i - nums[i];
            if(seen.containsKey(diff)){
                count += (i - seen.get(diff));
            }else{
                count += i;
            }
            seen.put(diff, seen.getOrDefault(diff, 0) + 1);
        }
        return count;
    }
}