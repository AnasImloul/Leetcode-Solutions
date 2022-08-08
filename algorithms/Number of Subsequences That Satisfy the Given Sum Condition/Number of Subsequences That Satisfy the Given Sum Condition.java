
class Solution {
    public int numSubseq(int[] nums, int target) {
        int n = nums.length;
        int i =0, j = n-1;
        int mod = (int)1e9+7;
        Arrays.sort(nums);
        int[] pow = new int[n];
        pow[0]=1;
        int count =0;
        for(int z =1;z<n;z++){
            pow[z] = (pow[z-1]*2)%mod;
        }
        
        while(i<=j){
            if((nums[i]+nums[j]) <= target){
                count=(count+pow[j-i])%mod;
                i++;
            }
            else if((nums[i]+nums[j]) > target)
                j--;
        }
        return count;
    }
}


