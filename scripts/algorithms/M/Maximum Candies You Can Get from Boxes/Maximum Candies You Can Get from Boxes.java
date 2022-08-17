class Solution {
    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[status.length];
        int answer = 0;
        for(int i=0;i<initialBoxes.length;i++) {
            queue.offer(initialBoxes[i]);
            visited[initialBoxes[i]] = true;
            for (int key : keys[initialBoxes[i]]) {
                status[key] = 1;
            }
        }
        while(!queue.isEmpty()) {
            int index = queue.poll();
            answer += candies[index];
            for(int key : keys[index]) {
                status[key] = 1;
            }
            if(containedBoxes[index].length > 0) {
                for(int next: containedBoxes[index]) {
                    for(int key : keys[next]) {
                        status[key] = 1;
                    }
                }
                for(int next: containedBoxes[index]) {
                    if(visited[next] || status[next] == 0) {
                        continue;
                    }
                    queue.offer(next);
                    visited[next] = true;
                }
            }
        }
        return answer;
    }
}
