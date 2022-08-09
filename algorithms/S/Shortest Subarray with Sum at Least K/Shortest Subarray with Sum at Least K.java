class Solution {
    public int shortestSubarray(int[] nums, int k) {
        
         TreeMap<Long, Integer> maps = new TreeMap<>();
         long sum = 0l;
         int min = nums.length + 1;
		 
         maps.put(0l, -1);
        
         for(int i = 0; i < nums.length; i++) {
             sum += nums[i];ntry(sum - k) != null) 
			       min = Math.min(min, i - maps.floorEntry(sum - k).getValue()); 
            while(!maps.isEmpty() && maps.lastEntry().getKey() >= sum) 
			       maps.remove(maps.lastEntry().getKey());
        
            maps.put(sum, i);
         }
        
        return min == (nums.length + 1) ? -1 : min;
    }
}
