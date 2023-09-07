// Runtime: 7 ms (Top 96.2%) | Memory: 40.32 MB (Top 56.2%)

class Solution {
     public static boolean isSolvable(String[] words, String result) {
	    // reverse all strings to facilitate add calculation.
        for (int i = 0; i < words.length; i++) {
            words[i] = new StringBuilder(words[i]).reverse().toString();
        }
        result = new StringBuilder(result).reverse().toString();
        if (!checkLength(words, result)) {
            return false;
        }
        boolean[] visited = new boolean[10];    // digit 0, 1, ..., 9
        int[] chToDigit = new int[26];
        Arrays.fill(chToDigit, -1);
        return dfs(0, 0, 0, visited, chToDigit, words, result);
    }

    /**
     * Elminate the case where result is too long
     * word1:  AAA
     * word2:  BBB
     * result: XXXXXXXXX
     */
    private static boolean checkLength(String[] words, String result) {
        int maxLen = 0;
        for (String word : words) {
            maxLen = Math.max(maxLen, word.length());
        }
        return result.length() == maxLen || result.length() == maxLen + 1;
    }

    /*
    Put all words like this:
    w1:     ABC
    w2:     EF
    w3:     GHIJ
    result: KLMNO
    i, is the row
    j,  is the column
    carrier, the one contributed from previous calculation
    chToDigit, 26 int array, which records choosen digit for 'A', 'B', 'C', ... If not choosen any, default is -1 
     */
    private static boolean dfs(int i, int j, int carrier, boolean[] visited, int[] chToDigit, String[] words, String result) {
        if (i == words.length) {
            char ch = result.charAt(j);
            // (i, i) at bottom right corner. final check
            if (j == result.length() - 1) {
                // 1. check if carrier is equal or greater than 10. If so, false.
                if (carrier >= 10) {
                    return false;
                }
                // 2. check if result.length() > 1 && result.lastCh is zero. If so the false.
                if (j > 0 && j == result.length() - 1 && chToDigit[ch - 'A'] == 0) {
                    return false;
                }
                // not selected, can select any. True.
                if (chToDigit[ch - 'A'] == -1) {
                    System.out.println(Arrays.toString(chToDigit));
                    return true;
                } else {    // if selected, check if it matches with carrier. Also, carrier can't be 0. result = '00' is invalid
                    return chToDigit[ch - 'A'] == carrier;
                }
            } else {    // reached normal result line.
                // 1. if not selected. Use current carrier's unit digit
                if (chToDigit[ch - 'A'] == -1) {
                    int selectedDigit = carrier % 10;
                    // For example carrier = 13. selectedDigit = 3. ch = 'H'. Should set 3 to 'H'.
                    // But 3 is already taken by 'B' previously. So wrong.
                    if (visited[selectedDigit]) {
                        return false;
                    }
                    visited[selectedDigit] = true;
                    chToDigit[ch - 'A'] = selectedDigit;
                    if (dfs(0, j + 1, carrier / 10, visited, chToDigit, words, result)) {
                        return true;
                    }
                    chToDigit[ch - 'A'] = -1;
                    visited[selectedDigit] = false;
                } else { // 2. selected
                    // just need to check if ch.digit equals to unit digit.
                    if (chToDigit[ch - 'A'] != carrier % 10) {
                        return false;
                    }
                    boolean ans = dfs(0, j + 1, carrier / 10, visited, chToDigit, words, result);
                    return ans;
                }
            } //
        } else { // normal word
            String word = words[i];
            // 1. check if j is equal or greater than word.len. If so pass to next word.
            if (j >= word.length()) {
                boolean ans = dfs(i + 1, j, carrier, visited, chToDigit, words, result);
                return ans;
            }
            // 2. check if it's last ch, word.len is greater than 1, and is '0'. If so false;
            if (j == word.length() - 1 && word.length() > 1 && chToDigit[word.charAt(j) - 'A'] == 0) {
                return false;
            }
            char ch = word.charAt(j);
            // 3. check if word.ch is selected. Just add current digit and move to next word.
            if (chToDigit[ch - 'A'] != -1) {
                int newSum = carrier + chToDigit[ch - 'A'];
                boolean ans = dfs(i + 1, j, newSum, visited, chToDigit, words, result);
                return ans;
            } else {
                for (int k = 0; k < visited.length; k++) {
                    if (visited[k]) {
                        continue;
                    }
                    visited[k] = true;
                    chToDigit[ch - 'A'] = k;
                    int newSum = k + carrier;
                    boolean ans = dfs(i + 1, j, newSum, visited, chToDigit, words, result);
                    if (ans) {
                        return true;
                    }
                    visited[k] = false;
                    chToDigit[ch - 'A'] = -1;
                }
            }
        }
        return false;
    }
}