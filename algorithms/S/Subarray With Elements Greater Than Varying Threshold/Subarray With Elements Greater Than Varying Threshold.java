class Solution {
    public int validSubarraySize(int[] nums, int threshold) {
        int n = nums.length;
        int[] next_small = new int[n];
        int[] prev_small = new int[n];
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        Arrays.fill(next_small, n);
        Arrays.fill(prev_small, -1);
        for(int i=1;i<n;i++){
            while(!stack.isEmpty() && nums[stack.peek()] >= nums[i]){
                stack.pop();
            }    
            if(stack.size()!=0){
                prev_small[i] = stack.peek();
            }
            stack.push(i);
        }
        stack = new Stack<>();
        stack.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!stack.isEmpty() && nums[stack.peek()] >= nums[i]){
                stack.pop();
            }    
            if(stack.size()!=0){
                next_small[i] = stack.peek();
            }
            stack.push(i);
        }
        for(int i=0;i<n;i++){
            int len = next_small[i] - prev_small[i] - 1;
            if(threshold/(double)len < nums[i]){
                return len;
            }
        }
        return -1;
    }
}
