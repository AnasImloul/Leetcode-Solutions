class Solution {
    public int longestBeautifulSubstring(String word) {
      int max = 0;
      for(int i = 1;i<word.length();i++){
         int temp = 1;
         Set<Character> verify = new HashSet<>();
         verify.add(word.charAt(i-1));
         while(i < word.length() && word.charAt(i) >= word.charAt(i-1)){
            temp++;
            verify.add(word.charAt(i));
            i++;
         }
         max = verify.size() == 5 ? Math.max(max,temp) : max ;
      }

      return max;
    }
}