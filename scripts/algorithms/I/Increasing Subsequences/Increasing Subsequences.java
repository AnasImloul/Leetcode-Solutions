// Runtime: 48 ms (Top 13.29%) | Memory: 68.6 MB (Top 66.07%)
class Solution {
    HashSet<List<Integer>> set;
    public List<List<Integer>> findSubsequences(int[] nums) {
        set=new HashSet<>();

        dfs(nums,0,new ArrayList<>());

        List<List<Integer>> ans=new ArrayList<>();
        if(set.size()>0){
            ans.addAll(set);
        }
        return ans;
    }

    private void dfs(int nums[], int start, List<Integer> temp){
        if(start==nums.length) return;

        for(int i=start;i<nums.length;i++){
            if(temp.size()==0 || temp.get(temp.size()-1)<=nums[i]){
                temp.add(nums[i]);

                if(temp.size()>=2) set.add(new ArrayList<>(temp));

                dfs(nums,i+1,temp);
                temp.remove(temp.size()-1);
            }
        }
    }
}