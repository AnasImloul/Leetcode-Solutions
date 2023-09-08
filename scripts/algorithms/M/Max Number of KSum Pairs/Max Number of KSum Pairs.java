// Runtime: 35 ms (Top 35.1%) | Memory: 54.14 MB (Top 93.9%)

class Solution {
    public int maxOperations(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int ans=0;
        for(int i:nums){
            int remaining = k-i;
            if(map.containsKey(remaining)){
                ans++;
                if(map.get(remaining)==1){
                    map.remove(remaining);
                }
                else{
                    map.put(remaining, map.get(remaining)-1);
                }
            }
            else{
                map.put(i, map.getOrDefault(i, 0)+1);
            }
        }
        return ans;
    }
}