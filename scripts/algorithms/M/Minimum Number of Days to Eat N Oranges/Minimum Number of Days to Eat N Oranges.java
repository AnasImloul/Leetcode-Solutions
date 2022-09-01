// Runtime: 4 ms (Top 97.62%) | Memory: 41.6 MB (Top 89.76%)
class Solution {
    HashMap<Integer,Integer>map;
    public int minDays(int n) {
        map = new HashMap<>();
        map.put(0,0);
        map.put(1,1);
        return dp(n);
    }
    public int dp(int n){
        if(map.get(n)!=null)
            return map.get(n);
         int one = 1+(n%2)+dp(n/2);
         int two = 1+(n%3)+dp(n/3);
        map.put(n,Math.min(one,two));
        return map.get(n);
}
    }
        // int one = 1+(n%2)+cache(n/2);
        // int two = 1+(n%3)+cache(n/3);
