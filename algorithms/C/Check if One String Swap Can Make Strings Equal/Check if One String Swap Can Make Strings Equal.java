class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
     
      int[] s1Array = new int[26];
      int[] s2Array = new int[26];
      int counter = 0;
      for(int i = 0;i<s1.length();i++){
         char s = s1.charAt(i);
         char ss = s2.charAt(i);
         if(s != ss)
            counter++;
         if(counter > 2)
            return false;
          s1Array[s -'a']++;
         s2Array[ss -'a']++;
      }
      return Arrays.equals(s1Array, s2Array);
    }
}