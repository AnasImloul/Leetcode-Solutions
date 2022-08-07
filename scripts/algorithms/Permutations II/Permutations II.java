class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        boolean used[] = new boolean[nums.length];
        
        permutationsFinder(nums,ans,new ArrayList<>(),used);
        
        return ans;
    }
    
    static void permutationsFinder(int[] nums,List<List<Integer>> ans,List<Integer> list,boolean used[]){
        if(list.size() == nums.length){
            ans.add(new ArrayList<>(list));
            return;
        }
        
        for(int i=0;i<nums.length;i++){
            if(used[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
            list.add(nums[i]);
            used[i] = true;
            permutationsFinder(nums,ans,list,used);
            list.remove(list.size()-1);
            used[i] = false;
        }
    }
}
