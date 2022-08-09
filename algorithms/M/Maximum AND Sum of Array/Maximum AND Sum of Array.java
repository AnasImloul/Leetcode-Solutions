class Solution {

    public int maximumANDSum(int[] nums, int numSlots) {
        int[] slotWt = new int[numSlots+1];
        Map<Pair<Integer, String>, Integer> dp = new HashMap<>();
        return helper(0, nums, slotWt, numSlots, dp);
    }
    
    public int helper(int idx, int[] nums, int[] slotWt, int numSlots, Map<Pair<Integer, String>, Integer> dp){
        
        if(idx==nums.length) return 0;
        
        Pair<Integer, String> key = new Pair<>(idx, Arrays.toString(slotWt));
        if(dp.containsKey(key)) return dp.get(key);
        
        int maxi = Integer.MIN_VALUE;
        for(int k=1; k<=numSlots; k++){
            if(slotWt[k] < 2){
                slotWt[k]++;
                int ans = (nums[idx] & k) + helper(idx+1, nums, slotWt, numSlots, dp);
                slotWt[k]--;
                maxi = Math.max(maxi, ans);
            }
        }
        
        dp.put(key, maxi);
        return maxi;
    }
}
