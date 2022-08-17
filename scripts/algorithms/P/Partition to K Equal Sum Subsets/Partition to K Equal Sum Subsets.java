class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = Arrays.stream(nums).sum(), target = sum/k, n=nums.length;
        if (sum % k != 0){
            return false;
        }
        int[] s = new int[1<<n];
        for (int i = 1; i < 1<<n; i++){
            s[i]=(int)1e9;
            for (int j = 0; j < n && s[i]>0; j++){
                if ((i & 1 << j) > 0){
                    int cur = s[i^1<<j]+nums[j];
                    s[i]=Math.min(s[i], cur==target?0 : cur);
                }
            }
        }
        return s[(1<<n)-1]==0;
    }
}
