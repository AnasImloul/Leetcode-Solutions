// Runtime: 1 ms (Top 64.28%) | Memory: 40.90 MB (Top 7.16%)

class Solution {
    public int minimumOperations(int[] nums) {
        Set<Integer> s = new HashSet<>();
        int result = 0;
        if(nums[0] == 0 && nums.length == 1){
            return 0;
        }
        else{
        for (int num : nums) {
            s.add(num);
        }
        for (int num : nums) {
            s.remove(0);
        }
        result = s.size();;
        }
        return result;
    }
}
