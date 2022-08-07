class Solution {
    public String reverseWords(String s) {
        if(s == null || s.trim().equals("")){
            return null;
        }
        String [] words = s.split(" ");
        StringBuilder resultBuilder = new StringBuilder();
        for(String word: words){
            for(int i = word.length() - 1; i>=0; i --){
                resultBuilder.append(word.charAt(i));
            }
            resultBuilder.append(" ");
        }
        return resultBuilder.toString().trim();
    }
}
