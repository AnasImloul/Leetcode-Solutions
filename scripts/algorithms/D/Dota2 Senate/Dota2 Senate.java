// Two Queues Solution
// Two queues to store the R index and D index.
// If the senate can execute his right, the senate is alive and can execute in the next round.
// Then we can add the senate back to the queue and process in the next round (idx + N).
// Time complexity: O(N), each loop we add/remove 1 senate in the queue.
// Space complexity: O(N)
class Solution {
    public String predictPartyVictory(String senate) {
        if (senate == null || senate.length() == 0) throw new IllegalArgumentException("Invalid input.");
        final int N = senate.length();
        Queue<Integer> queR = new ArrayDeque<>();  // store the R index
        Queue<Integer> queD = new ArrayDeque<>();  // store the D index
        for (int i = 0; i < N; i++) {
            if (senate.charAt(i) == 'R') {
                queR.add(i);
            } else {
                queD.add(i);
            }
        }
        while (!queR.isEmpty() && !queD.isEmpty()) {
            int r = queR.poll();
            int d = queD.poll();
            if (r < d) {  // R is alive in the next round.
                queR.add(r + N);
            } else {  // D is alive in the next round.
                queD.add(d + N);
            }
        }
        return queR.isEmpty() ? "Dire" : "Radiant";
    }
}
