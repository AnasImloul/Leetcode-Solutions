class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> storage = new HashSet();
        
        for(int i = 0; i < nums.length; i++){
            storage.add(nums[i]);
        }
        
        int maxL = 0;
        
        for(int i = 0; i < nums.length; i++){
            
            //check if nums[i] id present in set or not
            //since after checking in set we remove the element from 
            //set, there is no double calculation for same sequence 
            if(storage.contains(nums[i])){
                storage.remove(nums[i]);
                
                int dec = nums[i]-1;
                int inc = nums[i]+1;
                int tempL = 1;
                
                //check both ways from nums[i] and calculate 
                //tempL. since we are removing elements from 
                //set we only calculate once for every sequence.
                
                while(storage.contains(dec)){
                    storage.remove(dec);
                    dec--;
                    tempL++;
                }
                
                while(storage.contains(inc)){
                    storage.remove(inc);
                    inc++;
                    tempL++;
                }
                
                
                maxL = Math.max(maxL, tempL);
                
            }
        }
        
        return maxL;
    }
}
