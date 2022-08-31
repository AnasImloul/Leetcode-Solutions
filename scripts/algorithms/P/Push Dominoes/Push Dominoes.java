// Runtime: 11 ms (Top 100.00%) | Memory: 43.4 MB (Top 96.04%)
// Time complexity: O(N)
// Space complexity: O(N), where N is the length of input string
class Solution {
    public String pushDominoes(String dominoes) {
        // ask whether dominoes could be null
        final int N = dominoes.length();
        if (N <= 1) return dominoes;
        char[] res = dominoes.toCharArray();
        int i = 0;
        while (i < N) {
            if (res[i] == '.') {
                i++;
            } else if (res[i] == 'L') { // push left
                int j = i-1;
                while (j >= 0 && res[j] == '.') {
                    res[j--] = 'L';
                }
                i++;
            } else { // res[i] == 'R'
                int j = i+1;
                while (j < N && res[j] == '.') { // try to find 'R' or 'L' in the right side
                    j++;
                }
                if (j < N && res[j] == 'L') { // if found 'L', push left and right
                    for (int l = i+1, r = j-1; l < r; l++, r--) {
                        res[l] = 'R';
                        res[r] = 'L';
                    }
                    i = j + 1;
                } else { // if no 'L', push right
                    while (i < j) {
                        res[i++] = 'R';
                    }
                }
            }
        }
        return String.valueOf(res);
    }
}