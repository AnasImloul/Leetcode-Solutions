class Solution {
    public String firstPalindrome(String[] words) {

        for(int i=0; i<words.length;i++){
            StringBuilder sb = new StringBuilder();
            sb.append(words[i]);
            sb.reverse();
            // System.out.println(words[i]+" "+sb);
            if(words[i].equals(sb. toString())){
                return words[i];
            }
        }
        return "";
    }
}
