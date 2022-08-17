class Solution {
     public int findTheLongestSubstring(String s) {
        int res = 0 , mask = 0, n = s.length();
        HashMap<Integer, Integer> seen = new HashMap<>();// key--> Mask, value--> Index
        seen.put(0, -1);
        for (int i = 0; i < n; ++i) {
            if(s.charAt(i)=='a' || s.charAt(i)=='e' || s.charAt(i)=='i' || s.charAt(i)=='o' || s.charAt(i)=='u'){ // check only vowels and skip consonant
                int c=s.charAt(i);
                mask=mask ^ c;
                seen.putIfAbsent(mask, i);
            }            
            res = Math.max(res, i - seen.get(mask));
        }
        return res;
    }
}
