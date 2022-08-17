class Solution {
    class Node{
        long val, displace;
        Node(long val, long displace){
            this.val = val;
            this.displace = displace;
        }
    }
    public long subArrayRanges(int[] nums) {
        
        //lesser than current element
        Stack<Node> stack = new Stack<>();
        //from left
        long [] lesserLeft = new long[nums.length];
        for (int i = 0; i< nums.length; i++){
            long count = 1;
            while(stack.size()>0 && stack.peek().val<=nums[i]){
                count+=stack.pop().displace;
            }
            stack.add(new Node(nums[i], count));
            lesserLeft[i] = count;
        }
        stack.clear();
        //from right
        long[] lesserRight = new long[nums.length];
        for (int i = nums.length-1; i>=0; i--){
            long count = 1;
            while(stack.size()>0 && stack.peek().val<nums[i]){
                count+=stack.pop().displace;
            }
            stack.add(new Node(nums[i], count));
            lesserRight[i] = count;
        }
        
        
        //greater than current element
        stack.clear();
        //from left
        long [] greaterLeft = new long[nums.length];
        for (int i = 0; i< nums.length; i++){
            long count = 1;
            while(stack.size()>0 && stack.peek().val>=nums[i]){
                count+=stack.pop().displace;
            }
            stack.add(new Node(nums[i], count));
            greaterLeft[i] = count;
        }
        stack.clear();
        //from right
        long[] greaterRight = new long[nums.length];
        for (int i = nums.length-1; i>=0; i--){
            long count = 1;
            while(stack.size()>0 && stack.peek().val>nums[i]){
                count+=stack.pop().displace;
            }
            stack.add(new Node(nums[i], count));
            greaterRight[i] = count;
        }        
        
        long ans = 0;
        //Now we subtract the count of minimum occurrences from the count of maximum occurrences
        
        for (int i = 0; i< nums.length; i++){
            ans+=((lesserLeft[i]*lesserRight[i]) - (greaterLeft[i]*greaterRight[i]))*nums[i];
        }
        return ans;
    }
}
