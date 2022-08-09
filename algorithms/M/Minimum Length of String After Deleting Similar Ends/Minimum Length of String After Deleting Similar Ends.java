class Solution {
    public int minimumLength(String s) {
        int length = s.length();
        char[] chars = s.toCharArray();
        for(int left = 0,right = chars.length-1;left < right;){
            if(chars[left] == chars[right]){
                char c = chars[left];
             while(left < right && chars[left] == c ){
                    left++;
                    length--;

                }

                while (right >= left && chars[right] == c){
                    right--;
                    length--;

                }
            }else {
                break;
            }
        }
        return length;
    }
}