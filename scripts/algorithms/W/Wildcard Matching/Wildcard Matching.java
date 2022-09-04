// Runtime: 2 ms (Top 100.00%) | Memory: 42.3 MB (Top 99.02%)
class Solution {
    public boolean isMatch(String s, String p) {
        int i=0;
        int j=0;
        int starIdx=-1;
        int lastMatch=-1;

        while(i<s.length()){
            if(j<p.length() && (s.charAt(i)==p.charAt(j) ||
              p.charAt(j)=='?')){
                i++;
                j++;
            }else if(j<p.length() && p.charAt(j)=='*'){
                starIdx=j;
                lastMatch=i;
                j++;
            }else if(starIdx!=-1){
            //there is a no match and there was a previous star, we will reset the j to indx after star_index
            //lastMatch will tell from which index we start comparing the string if we encounter * in pattern
                j=starIdx+1;
                lastMatch++; // we are saying we included more characters in * so we incremented the index
                i=lastMatch;

            }else{
                return false;
            }
        }

        while(j<p.length() && p.charAt(j)=='*') j++;

        if(i!=s.length() || j!=p.length()) return false;

        return true;

    }
}