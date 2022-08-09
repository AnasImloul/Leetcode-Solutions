class Solution {
    private String getFreqString(String s) {
        int len = s.length();
        StringBuilder freqString = new StringBuilder();
        int currFreq = 1;
        char prevChar = s.charAt(0);
        freqString.append(s.charAt(0));
        for(int i = 1; i<len; i++) {
            if(s.charAt(i) == prevChar) {
                currFreq++;
            } else {
                freqString.append(currFreq);
                freqString.append(s.charAt(i));
                currFreq = 1;
            }
            prevChar = s.charAt(i);
        }
        
        if(currFreq>0) {
            freqString.append(currFreq);
        }
        
        return freqString.toString();
    }
    
    private boolean isGreaterButLessThanThree(char sChar, char wChar) {        
        return sChar > wChar && sChar < '3';
    }
    
    private boolean isStretchy(String s, String word) {    
        int sLen = s.length();
        int wordLen = word.length();
        
        if(sLen != wordLen) {
            return false;
        }
        
        for(int i = 0; i<sLen; i++) {
            char sChar = s.charAt(i);
            char wChar = word.charAt(i);
            if(i%2 != 0) {       
                if(sChar < wChar) {
                    return false;
                } if(isGreaterButLessThanThree(sChar, wChar)) {
                    return false;
                }
                
            } else if(sChar != wChar){
                    return false;
            }
        }
        
        return true;
    }
    
    public int expressiveWords(String s, String[] words) {
        int wordLen = words.length;
        if(wordLen < 1 || s.length() < 1) {
            return 0;
        }
        
        int stretchyWords = 0;
        String freqStringS = getFreqString(s);
        for(String word: words) {
            String freqStringWord = getFreqString(word); 
            if(isStretchy(freqStringS, freqStringWord)) {
                stretchyWords++;
            }
            
        }  
        return stretchyWords;
    }
}
