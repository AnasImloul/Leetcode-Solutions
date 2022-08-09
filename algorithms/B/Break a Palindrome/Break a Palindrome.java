class Solution {
    public String breakPalindrome(String palindrome) {
        
        int left = 0;
        int right = palindrome.length()-1;
        
        if(palindrome.length()==1)
            return "";
        
        while(left<right){
            
            char c = palindrome.charAt(left);
            
            if(c!='a'){
                StringBuilder sb = new StringBuilder(palindrome);
                sb.setCharAt(left,'a');
                return sb.toString();
            } 
            else{
                left++;
                right--;
            }
            
        
        }
       
        // aaaa
        // aba
        
        
              StringBuilder sb = new StringBuilder(palindrome);
                sb.setCharAt(palindrome.length()-1,'b');
                return sb.toString();
        
    
    }
}
