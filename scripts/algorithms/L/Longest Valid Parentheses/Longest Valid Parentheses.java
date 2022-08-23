// Runtime: 1644 ms (Top 5.15%) | Memory: 43.1 MB (Top 65.80%)
class Solution {
    public int longestValidParentheses(String s) {
        int i=0;
        int len=0;
        while(i<s.length()){
            int j=i;
            int open=0;
            int closed=0;
            while(j<s.length()){
                char ch = s.charAt(j);
                if(ch=='(') open++;
                if(ch==')') closed++;
                if(closed>open) break;
                if(open==closed) len=Math.max(len,j-i+1);

                j++;
            }
            i++;
        }
        return len;
    }
}