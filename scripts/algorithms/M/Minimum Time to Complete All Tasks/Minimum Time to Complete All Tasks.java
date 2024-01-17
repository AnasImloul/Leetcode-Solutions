// Runtime: 20 ms (Top 84.62%) | Memory: 45.10 MB (Top 56.41%)

class Solution {
    public int findMinimumTime(int[][] tasks) {
        Arrays.sort(tasks, (t1, t2) -> (t1[1] - t2[1]));
        
        boolean[] visited = new boolean[2010];
		int count = 0;
		for (int i = 0; i < tasks.length; i++) {
			int nums = 0;
            // check how many we already completed
			for (int j = tasks[i][0]; j <= tasks[i][1]; j++) {
				if (visited[j]) {
					nums++;
				}
			}
			int j = tasks[i][1];
            // complete remainings.
			while (nums < tasks[i][2]) { 
				if (!visited[j]) {
					count++;
					nums++;
					visited[j] = true; 
				}
				j--;
			}
		}
		return count;

    }
}
