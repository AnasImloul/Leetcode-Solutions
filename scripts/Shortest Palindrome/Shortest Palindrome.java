class Solution {
    public String shortestPalindrome(String s) {
        for(int i=s.length()-1; i >= 0; i--){
            if(isPalindrome(s, 0, i)){
                String toAppend = s.substring(i+1);
                String result = new StringBuilder(toAppend).reverse().append(s).toString();
                return result;
            }
        }
        String result = new StringBuilder(s).reverse().append(s).toString();
        return result;        
    }
    
    boolean isPalindrome(String s, int left, int right){
        while(left < right){
            if(s.charAt(left) != s.charAt(right))
                return false;
            left++;
            right--;
        }
        return true;
    }
}
