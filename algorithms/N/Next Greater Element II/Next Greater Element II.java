class Solution {
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer>s=new Stack<>();
        for(int i=nums.length-1;i>=0;i--){
            s.push(nums[i]);
        }
        for(int i=nums.length-1;i>=0;i--){
            int num=nums[i];
            while(!s.isEmpty() && s.peek()<=nums[i]){
                s.pop();
            }
            nums[i]=s.empty()?-1:s.peek();
            s.push(num);
        }
        return nums;
    }
}
