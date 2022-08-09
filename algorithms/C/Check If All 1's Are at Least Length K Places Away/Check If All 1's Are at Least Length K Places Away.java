class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        HashMap<Integer, Integer> hMap = new HashMap<>();
         for (int i = 0; i < nums.length; i++) {
             if(nums[i] == 1){
                 hMap.put(i, 1);
             }
         }
        if(hMap.isEmpty()){
            return true;
         }
         Integer[] key = hMap.keySet().toArray(new Integer[0]);
        if(nums.length == key.length){
            return true;
         }
         int count = key.length -1;
         for (int i = 1; i < key.length; i++) {
            if((key[i] - key[i-1]) >= k+1){
                count --;
            }
         }
         if(count ==0){
            return true;
         }
         return false;
    }
}
