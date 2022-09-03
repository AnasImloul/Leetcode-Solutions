// Runtime: 10 ms (Top 46.31%) | Memory: 43.1 MB (Top 83.52%)
class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int ans =0;
        int tempcost =0;
        int l =0 ;
        int r= 0 ;
        for(;r!=s.length();r++){
            tempcost += Math.abs(s.charAt(r)-t.charAt(r));
            while(tempcost>maxCost){
                tempcost -= Math.abs(s.charAt(l)-t.charAt(l));
                l++;
            }
            ans =Math.max(ans,r+1-l);
        }
        return ans;
    }
}