class Solution {
    ArrayList<Integer> ll=new ArrayList<>();
    public Solution(int[] nums) {
        for(int i=0;i<nums.length;i++){
            ll.add(nums[i]);
        
        }
    }
    public int pick(int target) {
        double a=Math.random();
        int n=(int)(a*this.ll.size());
        while(this.ll.get(n)!=target){
            a=Math.random();
            n=(int)(a*this.ll.size());
        }
        return n; 
    }
}