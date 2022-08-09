class Solution {
    public int prefixCount(String[] words, String pref) {
    int c = 0;
    for(String s : words) {
        if(s.indexOf(pref)==0) 
            c++;
    }
    return c; 
    }
}
