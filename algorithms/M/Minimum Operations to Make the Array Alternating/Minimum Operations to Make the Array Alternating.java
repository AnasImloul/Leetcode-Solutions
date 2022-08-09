class Solution {
    public int minimumOperations(int[] nums) {
        int freq[][] = new int[100005][2];
        int i, j, k, ans=0;
        for(i = 0; i < nums.length; i++) {
    			freq[nums[i]][i&1]++;
    		}
    		
    		for(i = 1, j=k=0; i <= 100000; i++) {
			// Add the maximum frequency of odd indexes to maximum frequency even indexes 
		    //and vice versa, it will give us how many elements we don't need to change. 
    		ans = Math.max(ans, Math.max(freq[i][0] + k, freq[i][1] + j));
            j = Math.max(j, freq[i][0]);
            k = Math.max(k, freq[i][1]);
        }
        return nums.length - ans;
    }
}
