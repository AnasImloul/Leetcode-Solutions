class Solution {
    public int maxWidthRamp(int[] nums) {
        Stack<Integer> s = new Stack<>();
        int res = 0;
        for(int i = 0; i< nums.length; i++){
            if(!s.isEmpty() && nums[s.peek()]<=nums[i]) {
                res = Math.max(res, i-s.peek());
                continue;
            }
            s.push(i);
        }
        int i = nums.length-1;
        while(!s.isEmpty() && i>=0){
            if(nums[s.peek()]<=nums[i]){
                res = Math.max(res, i-s.peek());
                s.pop();
            }else{
                i--;
            }
        }
        return res;
    }
}
