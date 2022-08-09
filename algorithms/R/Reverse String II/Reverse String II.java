class Solution {
    public String reverseStr(String s, int k) {
        char[] ch=s.toCharArray();
        int cnt=1,i=0;
        StringBuilder sb=new StringBuilder();
        String ans="";
        if(k>=s.length()){
            sb.append(s);
            sb.reverse();
            return sb.toString();
        }
        for(i=0;i<s.length()-k;i+=k){
            String str=s.substring(i,i+k);
            if(cnt%2!=0){
                sb.append(str);
                sb.reverse();
                ans+=sb.toString();
                cnt++;
                sb=new StringBuilder();
            }
            else{
                ans+=str;
                cnt++;
            }
        }
        if(cnt%2!=0){
            sb.append(s.substring(i,s.length()));
            sb.reverse();
            ans+=sb.toString();
        }
        else{
            ans+=s.substring(i,s.length());
        }
        return ans;
    }
}
