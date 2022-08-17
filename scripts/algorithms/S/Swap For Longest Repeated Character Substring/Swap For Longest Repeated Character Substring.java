class Solution {
    public int maxRepOpt1(String text) {
        int res = 0;
        int[] cnt = new int[26];
        for(char c : text.toCharArray()) cnt[c - 'a']++;
        for(char curChar = 'a';curChar<='z';curChar++){
        /*
        Check every lowercase letter
        1. Count the gap between the last occurrence with this time
        2. Count the number of continuous occurrence for current letter
        3. 
            (1) If the gap is 1
                If the number of occurrences of this time and last is smaller than the total, the letter between these two substring can be replaced by another character.
                If not, the largest result for current letter is the total number of occurrences of current letter
            (2) For other situations
                If the number of occurrences of this time is equal to the total number of occurrences of current letter, the result for the whole string might can be updated.
                If not, we can replace the former one or the later one letter with one current letter
            
        */
            int pre = 0, cur = 0;
            int idx = 0, gap = 0;
            while(idx < text.length()){
                while(idx < text.length() && text.charAt(idx) != curChar){
                    idx++;
                    gap++;
                }
                while(idx < text.length() && text.charAt(idx) == curChar){
                    idx++;
                    cur++;
                }
                if(gap == 1){
                    if(cur+ pre < cnt[curChar-'a']) res = Math.max(cur + pre + 1, res);
                    else  res = Math.max(cur + pre, res);
                }
                else{
                    if(cur == cnt[curChar - 'a']) res = Math.max(cur, res);
                    else res = Math.max(cur+1, res);
                }
                pre = cur;
                cur = 0;
                gap = 0;
            }
        }
        return res;
    }
}
