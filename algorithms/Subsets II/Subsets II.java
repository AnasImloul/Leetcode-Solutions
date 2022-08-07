class Solution {
    
    Set<List<Integer>> result = new HashSet<>();
    int nums[];
    
    
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        
        this.nums = nums;
        traverse(new ArrayList(), 0);
        
        List<List<Integer>> list = new ArrayList();
        for(List<Integer> i : result)
            list.add(i);
        return list;
        
        
    }
    
    void traverse(List<Integer> list, int index){
        if(index >= nums.length){
            result.add(new ArrayList(list));
            return;
        }
        list.add(nums[index]);
        traverse(list, index+1);
        list.remove(Integer.valueOf(nums[index]));
        traverse(list, index+1);
        
    }
    
}
