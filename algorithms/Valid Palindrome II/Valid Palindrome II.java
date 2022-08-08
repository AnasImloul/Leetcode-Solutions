class Solution {
    boolean first = false;
    public boolean validPalindrome(String s) {
        int left = 0;
        int right = s.length()-1;
        
        
        while(left <= right){
            if( s.charAt(left) == (s.charAt(right))){
                left++;
                right--;
            }else if(!first){
                first = true;
                String removeLeft = s.substring(0,left).concat(s.substring(left+1));
                String removeright = s.substring(0,right).concat(s.substring(right+1));
                left++;
                right--;
                return validPalindrome(removeLeft) || validPalindrome(removeright);   
            } else {
                return false;
            }
        }
     return true;   
    }
}
