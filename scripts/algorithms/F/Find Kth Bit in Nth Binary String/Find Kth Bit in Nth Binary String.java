// Runtime: 2755 ms (Top 5.21%) | Memory: 238.8 MB (Top 5.21%)
class Solution {
   private String invert(String s){
        char [] array=s.toCharArray();
        for(int i=0;i<s.length();i++){
            if(array[i]=='1'){
                array[i]='0';
            }
            else{
                array[i]='1';
            }
        }
        return new String(array);
    }
    private String reverse(String s){
        StringBuilder str=new StringBuilder(s);
        return str.reverse().toString();
    }
    private String func(int i){
        if(i==0){
            return "0";
        }
        return func(i-1)+"1"+reverse(invert(func(i-1)));
    }
    public char findKthBit(int n, int k) {
        String s=func(n-1);
        return s.charAt(k-1);
    }
}