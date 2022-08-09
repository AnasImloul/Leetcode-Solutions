class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> hs = new HashSet<>();
        for(int i=0;i<nums.length-1;i++){
            hs.add(nums[i]);
            if(hs.contains(nums[i+1])){
                return true;
            }
        }
        return false;
    }
}
