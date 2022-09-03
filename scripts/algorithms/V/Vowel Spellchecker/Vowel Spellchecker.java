// Runtime: 184 ms (Top 7.48%) | Memory: 114.1 MB (Top 5.44%)
class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        String[] ans = new String[queries.length];
        Map<String, String>[] map = new HashMap[3];
        Arrays.setAll(map, o -> new HashMap<>());
        String pattern = "[aeiou]";

        for (String w : wordlist){
            String lo = w.toLowerCase();
            map[0].put(w, "");
            map[1].putIfAbsent(lo, w);
            map[2].putIfAbsent(lo.replaceAll(pattern, "."), map[1].getOrDefault(w, w));
        }

        int i = 0;
        for (String q : queries){
            String lo = q.toLowerCase();
            String re = lo.replaceAll(pattern, ".");
            if (map[0].containsKey(q)){
                ans[i] = q;
            }else if (map[1].containsKey(lo)){
                ans[i] = map[1].get(lo);
            }else if (map[2].containsKey(re)){
                ans[i] = map[2].get(re);
            }else{
                ans[i] = "";
            }
            i++;
        }

        return ans;
    }
}