class Solution {
    public String replaceDigits(String s) {
        char[] str = s.toCharArray();
        
        for(int i=0;i<str.length;i++){
            if(Character.isDigit(str[i])){
              str[i] = shift(str[i-1],str[i]);
            }
        }
        return String.valueOf(str);
    }
    
    
    char shift(char letter, char number){
        int a = Integer.parseInt(String.valueOf(number));
        int asci = (int)letter;
        char c = (char)(asci + a);
        return c;
    }
}
