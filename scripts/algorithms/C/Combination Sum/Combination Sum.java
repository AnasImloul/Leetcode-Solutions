// Runtime: 5 ms (Top 69.68%) | Memory: 45.9 MB (Top 24.67%)
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer> cur = new ArrayList<>();
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(candidates);
        dfs(0, candidates, target, 0, cur, result);
        return result;
    }
    public void dfs(int start, int[] candidates, int target, int sum, List<Integer> cur, List<List<Integer>> result){
        if(sum == target){
            result.add(new ArrayList<>(cur));
            return;
        }
        for(int i = start; i < candidates.length; i++) {
            if(sum + candidates[i] <= target) {
              cur.add(candidates[i]);
              dfs(i, candidates, target, sum + candidates[i], cur, result);
              cur.remove((cur.size()- 1));
            }
        }
        return;
    }
}