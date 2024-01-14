// Runtime: 5 ms (Top 87.58%) | Memory: 41.90 MB (Top 54.72%)

class Solution {
    public String getHint(String secret, String guess) {
        int bulls = 0, cows = 0;

        int[] secretFreq = new int[10],
        guessFreq = new int[10];

        for (int i = 0; i < secret.length(); i++) {
            char s = secret.charAt(i);
            char g = guess.charAt(i);

            if (s == g) bulls++;
            else {
                secretFreq[s - '0']++;
                guessFreq[g - '0']++;
            }
        }

        for (int i = 0; i < 10; i++) {
            cows += Math.min(secretFreq[i], guessFreq[i]);
        }

        return bulls + "A" + cows + "B";
    }
}

// TC: O(n), SC: O(1)
