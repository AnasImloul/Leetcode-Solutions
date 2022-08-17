class Solution {
    public int uniqueLetterString(String s) {
        // int[] letter = new int[s.length()];
        int left;
        int right;
        int res = 0;
        for(int i = 0; i < s.length(); i ++){
            int j;
            for(j = i - 1; j >= 0; j --){
                if(s.charAt(j) == s.charAt(i)) break;
            }
            left = i - j;
            for(j = i + 1; j < s.length(); j ++){
                if(s.charAt(j) == s.charAt(i)) break;
            }
            right = j - i;
            res += left*right;
        }
        return res;
    }
}
