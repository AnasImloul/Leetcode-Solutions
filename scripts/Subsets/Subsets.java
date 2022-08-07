class Solution {
    
    private static void solve(int[] nums, int i, List<Integer> temp, List<List<Integer>> subset){
        
        if(i == nums.length){
            subset.add(new ArrayList(temp));
            return;
        }
        
        temp.add(nums[i]);
        solve(nums, i + 1, temp, subset);
        
        temp.remove(temp.size() - 1);
        solve(nums, i + 1, temp, subset);
    }
    
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> subset = new ArrayList();
        List<Integer> temp = new ArrayList<>();
        
        if(nums.length == 0) return subset;

        int startInd = 0;
        
        solve(nums, startInd, temp, subset);
            
        return subset;
    }
}
