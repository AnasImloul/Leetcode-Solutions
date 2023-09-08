// Runtime: 43 ms (Top 26.7%) | Memory: 43.29 MB (Top 18.2%)

class Solution {
    public int findTheWinner(int n, int k) {
	    // Initialisation of the LinkedList
        LinkedList<Integer> participants = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
		    participants.add(i);
		}
		
		int lastKilled = 0;
		// Run the game
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k-1; j++) {
			    participants.add(participants.poll());
			}
            lastKilled = participants.poll();
        }
        // Return the last one killed
        return lastKilled;
    }
}