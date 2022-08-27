// Runtime: 99 ms (Top 53.72%) | Memory: 100.9 MB (Top 52.07%)
class Solution {
    public int maxValue(int[][] events, int k) {
        Arrays.sort(events, (e1, e2) -> (e1[0] == e2[0] ? e1[1]-e2[1] : e1[0]-e2[0]));
        return maxValue(events, 0, k, 0, new int[k+1][events.length]);
    }

    private int maxValue(int[][] events, int index, int remainingEvents, int lastEventEndDay, int[][] dp) {
        // Return 0 if no events are left or maximum choice is reached
        if (index >= events.length || remainingEvents == 0)
            return 0;

        // An Event cannot be picked if the previous event has not completed before current event
        if (lastEventEndDay >= events[index][0])
            return maxValue(events, index+1, remainingEvents, lastEventEndDay, dp);

        // Return the value if the solution is already available
        if (dp[remainingEvents][index] != 0)
            return dp[remainingEvents][index];

        // There are 2 choices that we can make,
            // SKIP this meeting or PICK this meeting
        return dp[remainingEvents][index] = Math.max(
            maxValue(events, index+1, remainingEvents, lastEventEndDay, dp), // skip
            maxValue(events, index+1, remainingEvents-1, events[index][1], dp) + events[index][2] // pick
        );
    }
}