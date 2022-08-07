class Solution {
public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
    TreeSet<Long> treeSet = new TreeSet<>();
    //nums = [1,2,3,1], k = 3, t = 0
    for(int i = 0; i < nums.length; i++){
        Long cur = (long) nums[i];
        //greatest element that is less than or equal to current
        Long floor = treeSet.floor(cur);
        //smallest element that is greater than or equal to current
        Long ceiling = treeSet.ceiling(cur);
        
        if(null != floor && Math.abs(floor - cur) <= t)
            return true;
        
        if(null != ceiling && Math.abs(ceiling - cur) <= t)
            return true;
        
        treeSet.add(cur);
        if(treeSet.size() > k)
            treeSet.remove((long)nums[i-k]);            
    }
    return false;        
}
}