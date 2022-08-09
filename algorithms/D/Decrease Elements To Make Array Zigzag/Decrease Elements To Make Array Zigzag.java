class Solution {
    /*
        firstly, check elements in odd indices are greater than its neighbours.
        if not, decrease its neigbours and update the cost.
        
        do same thing for even indices, because there can be two combinations as indicated in question.
    */
    
    private int calculateCost(int[] nums, int start){
        int res = 0;
        int n = nums.length;
        int[] arr = Arrays.copyOf(nums, nums.length); // nums array will be modified, so copy it.
        
        for(int i=start;i<n;i+=2){
            int prev = (i==0) ? Integer.MIN_VALUE : arr[i-1]; 
            int cur = arr[i];
            int next = (i == n-1) ? Integer.MIN_VALUE : arr[i+1];
            
            if(prev < cur && next < cur)
                continue;
        
            if(prev >= cur){
                res += prev-cur +1;
                arr[i-1] = cur-1;
            } 
            
            if(next >= cur){
                res += next-cur +1;
                arr[i+1] = cur-1;
            }
        }
        return res;
    }
        
    public int movesToMakeZigzag(int[] nums) {
        return Math.min(calculateCost(nums, 0), calculateCost(nums,1));
    }
}
