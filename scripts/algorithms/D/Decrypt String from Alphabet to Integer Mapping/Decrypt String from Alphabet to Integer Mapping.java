class Solution {
    public String freqAlphabets(String s) {
        Stack<Character> stk = new Stack<>();
        int i=0;
        String decoded="";
        while(i<s.length()) {
            if(s.charAt(i)=='#') { // if # is encountered, convert and store corresponding alphabet
                int c1=stk.pop()-48;
                int c2=stk.pop()-48;
                int c = 96+(10*c2)+c1;
                stk.push((char)c);
                
            } else {
                stk.push(s.charAt(i));
            }
            i++;
        }
        
        String temp="";
        
        while(!stk.isEmpty()) {
            char c=stk.pop();
            if(c>='1' && c<='9') {
                int val=48+c;
                temp=(char)val+"";
            } else {
                temp=c+"";
            }
            decoded=temp+decoded;
        }
        return decoded;
    }
}