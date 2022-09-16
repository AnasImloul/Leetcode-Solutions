// Runtime: 77 ms (Top 56.41%) | Memory: 91.9 MB (Top 81.62%)
class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        Map<String, String> map = new HashMap<>();
        for(List<String> ele : knowledge) {
            map.put(ele.get(0), ele.get(1));
        }
        StringBuilder sb = new StringBuilder();
        int b_start = -1;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '(') {
                b_start = i;
            } else if(s.charAt(i) == ')') {
                String key = s.substring(b_start + 1, i);
                sb.append(map.getOrDefault(key, "?"));
                b_start = -1;
            } else {
                if(b_start == -1) {
                    sb.append(s.charAt(i));
                }
            }
        }
        return sb.toString();
    }
}