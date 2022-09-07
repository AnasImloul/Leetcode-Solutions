// Runtime: 7 ms (Top 34.08%) | Memory: 44.9 MB (Top 74.04%)
class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        int total = 0;
        for(int i=0;i<nums.length;i++){
            total += nums[i];
        }
        Arrays.sort(nums);
        int sum = 0;
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i=nums.length-1;i>=0;i--){
            ans.add(nums[i]);
            sum += nums[i];
            if(sum>total-sum){
                return ans;
            }
        }
        return ans;
    }
}