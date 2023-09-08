// Runtime: 1 ms (Top 33.0%) | Memory: 40.70 MB (Top 50.3%)

class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
      List<Boolean> list = new ArrayList<>();

      for (var q : queries) {
         int index = 0;
         boolean flag = true;
         for (var c : q.toCharArray()) {
            if(index < pattern.length() && c == pattern.charAt(index)){
               index++;
               continue;
            }
            if(c >= 'A' && c <= 'Z'){
               if(index >= pattern.length() || c != pattern.charAt(index)){
                  flag = false;
                  break;
               }
            }
         }
         flag = flag && index == pattern.length();
         list.add(flag);
      }
      return list;
    }
}