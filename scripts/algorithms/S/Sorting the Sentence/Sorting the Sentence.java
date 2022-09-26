// Runtime: 2 ms (Top 59.85%) | Memory: 42 MB (Top 63.26%)
class Solution {
    public String sortSentence(String s) {
        String []res=new String[s.split(" ").length];
        for(String st:s.split(" ")){
            res[st.charAt(st.length()-1)-'1']=st.substring(0,st.length()-1);
        }
        return String.join(" ",res);
    }
}