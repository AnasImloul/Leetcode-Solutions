class Solution {
    public boolean matchReplacement(String s, String sub, char[][] mappings) {
        HashMap<Character, HashSet<Character>> m = new HashMap<>();
        for(char[] carr: mappings) {
            if (!m.containsKey(carr[0])){
                m.put(carr[0], new HashSet<Character>());
            }
            m.get(carr[0]).add(carr[1]);
        }
        int len_s = s.length();
        int len_sub = sub.length();
        for (int pos = 0; pos < s.length(); pos++ ){
            int i = pos;
            int j = 0;
            boolean cont = false; 
            while (j <= sub.length()) {
                if ( j == sub.length()) return true;
                int lenlefts = len_s - i;
                int lenleftsub = len_sub - j;
                if (lenlefts < lenleftsub) {
                    break;
                } else if ((s.charAt(i) == sub.charAt(j)) || 
				              (m.containsKey(sub.charAt(j)) && m.get(sub.charAt(j)).contains( s.charAt(i)))) {
                    i += 1;
                    j += 1;
                } else {
                    break;
                }
            }
        }
        return false;
    }
}
