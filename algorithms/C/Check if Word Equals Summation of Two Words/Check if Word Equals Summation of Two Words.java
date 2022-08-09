class Solution {
    public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
        int sumfirst=0, sumsecond=0, sumtarget=0;
        for(char c : firstWord.toCharArray()){
            sumfirst += c-'a';
            sumfirst *= 10;
        }
        for(char c : secondWord.toCharArray()){
            sumsecond += c-'a';
            sumsecond *= 10;
        }
        for(char c : targetWord.toCharArray()){
            sumtarget += c-'a';
            sumtarget *= 10;
        }
       
        return (sumfirst + sumsecond) == sumtarget;
    }
}