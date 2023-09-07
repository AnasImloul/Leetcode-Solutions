// Runtime: 2 ms (Top 43.3%) | Memory: 40.72 MB (Top 56.6%)

class Solution {
    public String freqAlphabets(String str) {
        HashMap<String, Character> map = new HashMap<>();
        int k = 1;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (ch < 'j')
                map.put(String.valueOf(k++), ch);
            else
                map.put(String.valueOf(k++)+"#", ch);
        }
        
        StringBuilder sb = new StringBuilder();
        int i = str.length() - 1;
        while (i >= 0) {
            if (str.charAt(i) == '#') {
                sb.append(map.get(str.substring(i - 2, i+1)));
                i -= 3;
            } else {
                sb.append(map.get(str.substring(i, i + 1)));
                i--;
            }
        }
        
        return sb.reverse().toString();
    }
}