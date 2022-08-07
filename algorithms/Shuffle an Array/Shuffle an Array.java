class Solution {

    int a[];
    int b[];
    public Solution(int[] nums) {
        a=nums.clone();
        b=nums.clone();
    }
    
    public int[] reset() {
        a=b.clone();
        return a;
    }
    
    public int[] shuffle() {
        
        for(int i=0;i<a.length;i++){
            int ren=(int)(Math.random()*a.length);
            int temp= a[ren];
             a[ren]=a[i];
            a[i]=temp;
        }
        return a;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
