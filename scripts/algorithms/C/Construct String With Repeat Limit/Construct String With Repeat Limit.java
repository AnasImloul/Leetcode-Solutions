// Runtime: 28 ms (Top 95.86%) | Memory: 64.6 MB (Top 55.86%)
class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        int[] counter = new int[26];
        int max = 0;
        for (char ch : s.toCharArray()) {
            int curr = ch - 'a';
            max = Math.max(max, curr);
            counter[curr]++;
        }
        int repeated = 0;
        StringBuilder builder = new StringBuilder();
        while (max >= 0) {
            builder.append((char)('a' + max));
            counter[max]--;
            repeated++;
            if (counter[max] == 0) {
                max = findNextMax(counter, max - 1);
                repeated = 0;
                continue;
            }
            if (repeated == repeatLimit) {
                // Greedy, use the next possible char once and get back to curr.
                // if no other char available, the curr word is the largest subsequence.
                int lower = findNextMax(counter, max - 1);
                if (lower < 0) {
                    return builder.toString();
                }
                builder.append((char)('a' + lower));
                counter[lower]--;
                repeated = 0;
            }
        }
        return builder.toString();
    }

    private int findNextMax(int[] counter, int from) {
        int curr = from;
        while (curr >= 0) {
            if (counter[curr] > 0) {
                return curr;
            }
            curr--;
        }
        return curr;
    }
}