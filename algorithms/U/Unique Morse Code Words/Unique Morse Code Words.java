class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        HashSet<String> set = new HashSet<>();
        String[] morse = new String[]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for (int i = 0; i < words.length; ++i) {
            String temp = "";
            for (int j = 0; j < words[i].length(); ++j) {
                temp += morse[(int)words[i].charAt(j)-'a'];
            }
            set.add(temp);
        }
        return set.size();
    }
}
