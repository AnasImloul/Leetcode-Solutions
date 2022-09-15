// Runtime: 158 ms (Top 89.09%) | Memory: 61.5 MB (Top 92.12%)
class Solution {
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {

        // use a tree to track available servers
        TreeSet<Integer> availableServerIdxs = new TreeSet<Integer>();
        for (int num = 0; num < k; num++) {
            availableServerIdxs.add(num);
        }
        // use a PQ to maintain the availability based on curTime + loadTime and the server index = idx%k
        Queue<int[]> runningServers = new PriorityQueue<>((a, b)->(a[0] - b[0]));

        int[] serverHandledReqCount = new int[k];

        for (int idx = 0; idx < arrival.length; idx++) {
            int newTaskCompletionTime = arrival[idx];

          // peek if the server's work time is less than or equal to the next task completion time, if it is poll those servers from the running servers queue and add the index of that server to the availableServerIdxs treeSet
            while (!runningServers.isEmpty() && runningServers.peek()[0] <= newTaskCompletionTime) {
                int freedServer = runningServers.poll()[1];
                availableServerIdxs.add(freedServer);
            }

            if (availableServerIdxs.size() == 0) continue; // all busy

            // to always get the last freed server
            Integer serverIdx = availableServerIdxs.ceiling(idx % k);

            if (serverIdx == null) {
                serverIdx = availableServerIdxs.first();
            }

            serverHandledReqCount[serverIdx]++;
            availableServerIdxs.remove(serverIdx);

            runningServers.offer(new int[] {newTaskCompletionTime + load[idx], serverIdx});
        }

        int max = Arrays.stream(serverHandledReqCount).max().getAsInt();
        return IntStream.range(0, k).filter(i -> serverHandledReqCount[i] == max).boxed().collect(Collectors.toList());

        //return findMaxesInCounter(counter);
    }

    /*
    private List<Integer> findMaxesInCounter(int[] counter) {
        int max = 0;
        for (int i = 0; i < counter.length; i++) {
            max = Math.max(max, counter[i]);
        }
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < counter.length; i++) {
            if (counter[i] == max) {
                result.add(i);
            }
        }
        return result;
    }
    */
}