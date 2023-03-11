class Solution {
    public int maxRepeating(String s, String w) {
        if(w.length()>s.length()) return 0;
        int ans=0;
        StringBuilder sb=new StringBuilder("");
        while(sb.length()<=s.length()){
            sb.append(w);
            if(s.contains(sb)) ans++;
            else break;
        }
        return ans;
    }
}