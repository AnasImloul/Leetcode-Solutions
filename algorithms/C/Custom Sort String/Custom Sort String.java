class Solution {
    public String customSortString(String order, String s) {
      if(s.length() <= 1) return s;
      
      StringBuilder finalString = new StringBuilder();
      HashMap<Character, Integer> hm = new HashMap<>();
      
      for(int i = 0; i < s.length(); i++) {
        char actualChar = s.charAt(i);
        
        if(order.indexOf(actualChar) == -1) {
          finalString.append(actualChar);
        } else {
          hm.put(actualChar, hm.getOrDefault(actualChar, 0) + 1);
        }
      }
      
      for(int i = 0; i < order.length(); i++) {
        char actualChar = order.charAt(i);
        
        if (hm.get(actualChar) != null){
          for(int j = 0; j < hm.get(actualChar); j++) {
            finalString.append(actualChar);
          }
        }
      }
      
      return finalString.toString(); 
    }
}
