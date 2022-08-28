// Runtime: 2 ms (Top 84.32%) | Memory: 39.8 MB (Top 90.27%)
class Solution {
    public int findLUSlength(String[] strs) {
        Arrays.sort(strs,(a,b) -> b.length() - a.length()); // sort descending order by length
         // store the frequency of all strings in array
        Map<String,Integer> map = new HashMap<>();
        for(String s : strs) map.put(s,map.getOrDefault(s,0)+1);

        for(int i=0;i<strs.length;i++){
            if(map.get(strs[i]) != 1) continue; // string is not unique
            int j;
            for(j=0;j<i;j++){
                if(isSubsequence(strs[i],strs[j])) break;
            }
            // if it is not a subsequence of any other larger string
             if(j == i) return strs[i].length();
        }
        return -1; // no string satisfies the criterion
    }
    public boolean isSubsequence(String a, String b){
        int i=0,j=0;
        while(i<a.length() && j<b.length())
            if(a.charAt(i) == b.charAt(j++)) i++;
        return i == a.length();
    }
}