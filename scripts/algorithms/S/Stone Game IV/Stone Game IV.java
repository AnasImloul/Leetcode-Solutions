// Runtime: 1188 ms (Top 5.04%) | Memory: 258.9 MB (Top 5.04%)
class Solution {
    // idea: Alice wins a game with n stones if and only if there exists
    // some perfect square p <= n such that Alice wins a game with
    // n - p stones... i.e., Bob DOES NOT win a game with n - p stones
    public boolean winnerSquareGame(int n) {
        // this bit would be better with just an array of booleans, but this
        // is how i thought of it at the time, so leaving it this way...
        // maybe it will be "more explicit" and help someone better understand dp?
        HashMap<Integer, Boolean> memo = new HashMap<>();
        memo.put(1, true); // if there is one stone in the pile to begin the game, the next player to go wins
        memo.put(0, false); // if there are zero stones in the pile to begin the game, the next player to go loses
        List<Integer> perfectSquares = new ArrayList<>();
        int i = 1;
        while (i * i <= n) {
            perfectSquares.add(i * i);
            i++;
        }
        // if there are some perfect square number of stones in the pile to begin the game, the next player to go wins
        perfectSquares.forEach(p -> memo.put(p, true));
        // Alice goes first...
        return this.playerWins(n, perfectSquares, memo);
    }

    private boolean playerWins(int n, List<Integer> P, HashMap<Integer, Boolean> m) {
        if (m.containsKey(n)) { return m.get(n); } // if we already computed the answer for n, just return it
        m.put(n, false); // otherwise, assume it's false to begin...
        for (Integer p : P) { // check every perfect square p...
            if (p <= n && !playerWins(n - p, P, m)) {
                // if p <= n AND the player who goes next (e.g., Bob) does not win a game that begins with
                // n - p stones, then we know that the player whose turn it is right now (e.g., Alice) wins
                // a game that begins with n stones, so record this discovery in the memo and then break out
                // of the loop because there's no more work to do...
                m.put(n, true);
                break;
            } // else p >= n OR taking p stones would not result in a win for the player whose turn it is right now...
        }
        // we put false in before the loop; if we never found a reason to change it to true,
        // then false is the correct result...
        return m.get(n);
    }

}