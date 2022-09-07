// Runtime: 3 ms (Top 40.49%) | Memory: 42.4 MB (Top 68.55%)
class Solution {
    public int maxPower(String s) {
        // O(n), assuming the access to every char is O(1)
        // iterate through characters
        // if char(n) == char(n+1) counter++
            // if counter > max, max = counter
        // else counter = 1 // 1 is init value because otherwise the compared char itself is not counted

        int maxConsecutive = 1; // 1 is init value because otherwise the compared char itself is not counted
        int counterConsecutive = 1;
        for(int i = 0; i< s.length()-1; i++){
            if(s.charAt(i) == s.charAt(i+1)){
                counterConsecutive++;
                maxConsecutive = Math.max(counterConsecutive, maxConsecutive);
            } else {
                counterConsecutive = 1;
            }
        }

        return maxConsecutive;
    }
}