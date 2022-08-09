class Solution {
    public int[] numberOfPairs(int[] nums) {
        
        if(nums.length == 1)
        return new int[]{0,1};
        
        HashSet<Integer> set = new HashSet<>();
        
        int pairs=0;
        for(int i : nums){
            if(!set.contains(i)){
               set.add(i);            // No pair present 
            }else{
              set.remove(i);          // Pair found 
              pairs++;                                              
            }
        }
        
        return new int[]{pairs,set.size()};             
    }
}
