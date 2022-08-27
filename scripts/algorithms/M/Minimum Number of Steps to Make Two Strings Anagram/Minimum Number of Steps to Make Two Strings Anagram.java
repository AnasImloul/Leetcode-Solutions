// Runtime: 16 ms (Top 64.38%) | Memory: 54.3 MB (Top 67.83%)
//find the frequency of every letter and check diffrence between the frequency of each letter then divide it by 2 to calculate the minimum number of letter to be changed.
class Solution {
    public int minSteps(String s, String t) {
        int sf[]=new int[26];
        int tf[]=new int[26];
        int diff=0;
        for(char c:s.toCharArray()){
            sf[c-'a']++;
        }
        for(char c:t.toCharArray()){
            tf[c-'a']++;
        }
        for(int i=0;i<26;i++){
            diff+=(int)Math.abs(sf[i]-tf[i]);
        }
        return diff/2;
    }
}