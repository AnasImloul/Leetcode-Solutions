class Solution {
    public int minTimeToType(String word) {
        char prevChar = 'a';
        int totalTime = word.length();
        for(int i = 0; i < word.length(); i++){
            char currChar = word.charAt(i);
            int diff = Math.abs(currChar - prevChar);
            totalTime += Math.min(diff, 26 - diff);
            prevChar = currChar;
        }
        
        return totalTime;
    }
}
