// Runtime: 0 ms (Top 100.0%) | Memory: 39.04 MB (Top 74.4%)

class Solution {
    public int countVowelStrings(int n) {
        int a=1,e=1,i=1,o=1,u=1;
        for(int k=1;k<n;k++){
            a=a+e+i+o+u;
            e=e+i+o+u;
            i=i+o+u;
            o=o+u;
        }
        return a+e+i+o+u;
    }
}