class Solution {
    
    private List<List<Integer>> result;
    private int target;
    private int[] candidates;
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        result = new ArrayList();
        this.target = target;
        this.candidates = candidates;
        Arrays.sort(this.candidates);
        traverse(new ArrayList(), 0,0);
        return result;
        
    }
    
    private void traverse(List<Integer> curr, int index, int sum){
        if(sum == target) result.add(new ArrayList(curr));
        if(sum >= target) return;
        
        int prev = -1;

        for(int i = index ; i<candidates.length; i++){
            if(prev == candidates[i]) continue;
            curr.add(candidates[i]);
            traverse(curr, i+1, sum+candidates[i]);
            curr.remove(Integer.valueOf(candidates[i]));
            prev = candidates[i];
        }
    }
    
}
