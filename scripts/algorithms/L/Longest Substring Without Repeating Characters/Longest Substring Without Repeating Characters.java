// Runtime: 310 ms (Top 7.97%) | Memory: 117.9 MB (Top 6.60%)
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> hash = new HashMap<>();
        int count = 0;
        int ans = 0;
        for(int i=0; i < s.length(); i++){
            if(hash.containsKey(s.charAt(i))){
                i = hash.get(s.charAt(i)) + 1;
                hash.clear();
                count = 0;
            }
            if(!hash.containsKey(s.charAt(i))){
                hash.put(s.charAt(i), i);
                count++;
                ans = Math.max(ans, count);
            }
        }
        return ans;
    }
}