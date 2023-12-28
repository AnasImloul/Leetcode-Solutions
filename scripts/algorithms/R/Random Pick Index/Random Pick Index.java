// Runtime: 85 ms (Top 42.59%) | Memory: 55.80 MB (Top 31.28%)

class Solution {
    Random random;
    int[] origin;
    
    public Solution(int[] nums) {
        random = new Random();
        origin = nums;
    }
    
    public int pick(int target) {
        
        while(true){
            int idx = random.nextInt(origin.length);
            if(origin[idx] == target){
                return idx;
            }
        }
    }
}
