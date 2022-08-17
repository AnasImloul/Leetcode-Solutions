class Solution {
    public int numOfPairs(String[] nums, String target) {
        
        HashMap<String, Integer> map = new HashMap<>();
        for (int i = 0; i<nums.length; i++){
            map.put(nums[i], map.getOrDefault(nums[i],0)+1);
        }
        
        int ans = 0, n = target.length();
        String a = "", b= "";
        for (int i = 1; i<n; i++){
            a = target.substring(0,i);
            b = target.substring(i,n);
            if (map.containsKey(a) && map.containsKey(b)){
                if (a.equals(b)) ans += (map.get(a) * (map.get(a)-1));
                else ans+= (map.get(a) * map.get(b));
            }
        }
        return ans;
    }
}
