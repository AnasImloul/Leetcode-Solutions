class Solution {
    public HashMap<String,Integer> cache ;
    public Solution() {
        cache = new HashMap<>();
    }
    public int findTargetSumWays(int[] nums, int target) {
        return dfs(nums,target,0,0);
    }
    
    HashMap<String,Integer> cache;
    public int lastStoneWeightII(int[] stones) {
        cache = new HashMap<>();
        return dfs(0,0,stones);
    }
    
    public int dfs(int index, int sum , int[] stones) {
        String key = index+","+sum;
        if(cache.containsKey(key)) {
            return cache.get(key);
        }
        if(index== stones.length) {
            return sum;
        }
        int currentValue = stones[index];
        int left = dfs(index+1,sum+currentValue,stones);
        int right = dfs(index+1,Math.abs(sum-currentValue),stones);
        int result = Math.min(left,right);
        cache.put(key,result);
        return result;
    }
    
}
