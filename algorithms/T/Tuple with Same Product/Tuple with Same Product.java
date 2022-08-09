class Solution {
    public int tupleSameProduct(int[] nums) {
        
        if(nums.length < 4){
            return 0;
        }
        
        int res = 0;
        
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(int i = 0; i < nums.length - 1; i++){
            
            for(int j = i + 1; j < nums.length; j++){
                
                int val = nums[i] * nums[j];
                map.put(val, map.getOrDefault(val, 0) + 1);
            }
        }
        
        for(int key : map.keySet()){
            
            int val = map.get(key);
            
            if(val > 1){
                res += val * (val - 1) * 4;    // (val * (val - 1) / 2) * 8
            }
        }
        
        return res;
    }
}
