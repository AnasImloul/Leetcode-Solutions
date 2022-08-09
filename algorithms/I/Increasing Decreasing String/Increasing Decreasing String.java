class Solution {
    public String sortString(String s) {
        
        StringBuilder result = new StringBuilder();
        int[] freq  = new int[26];
        for(char c: s.toCharArray()){
            freq[c-'a']++;
        }
        int remaining = s.length();
        while(remaining!=0){
            for(int i=0;i<26&&remaining!=0;i++){
                if(freq[i]!=0){
                    freq[i]--;
                    result.append((char)(i+'a'));
                    remaining--;
                }
            }
            for(int i=25;i>=0&&remaining!=0;i--){
                if(freq[i]!=0){
                    freq[i]--;
                    result.append((char)(i+'a'));
                    remaining--;
                }
            }
        }
        return result.toString();
    }
}
