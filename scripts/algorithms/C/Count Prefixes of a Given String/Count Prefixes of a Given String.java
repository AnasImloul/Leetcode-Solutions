class Solution {
    public int countPrefixes(String[] words, String s) {
        int i = 0;
        int j = 0;
        int count = 0;
        for(int k = 0; k < words.length; k++){
            if(words[k].length() > s.length()){
                continue;
            }
            
            while(i < words[k].length() && words[k].charAt(i) == s.charAt(j)){
                i++;
                j++;
            }
            if(i == words[k].length()){
                count++;
            }
            i = 0;
            j = 0;
        }
        return count;
    }
}
