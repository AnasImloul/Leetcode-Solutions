class Solution {
    List<List<Integer>> res = new ArrayList<>();
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        helper(candidates, new ArrayList<>(), target, 0, 0);
        return res;
            
    }
    
    public void helper(int [] candidates, List<Integer> path, int target, int sum, int start) {
        if (sum == target) {
            res.add(new ArrayList<>(path));
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            path.add(candidates[i]);
            helper(candidates, path, target, sum + candidates[i], i);
            path.remove(path.size() - 1);
        }
    } 
}
