// Runtime: 78 ms (Top 72.84%) | Memory: 71.20 MB (Top 35.03%)

class Solution {
    private static class Job {
		private int start;
		private int end;
		private int profit;

		public Job(int start, int end, int profit) {
			this.start = start;
			this.end = end;
			this.profit = profit;
		}
	}
    
    private int binarySearch(Job jobs[], int index) {
		int low = 0;
		int high = index - 1;
		int ans = -1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (jobs[mid].end <= jobs[index].start) {
				ans = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return ans;
	}
    
    public long maxTaxiEarnings(int n, int[][] rides) {
		Job jobs[] = new Job[rides.length];
		for (int i = 0; i < rides.length; i++) {
			jobs[i] = new Job(rides[i][0], rides[i][1], rides[i][1] - rides[i][0] + rides[i][2]);
		}
		Arrays.sort(jobs, (j1, j2) -> (j1.end - j2.end));
		long[] dp = new long[rides.length];
		dp[0] = jobs[0].profit;
		for (int i = 1; i < jobs.length; i++) {
			long include = jobs[i].profit;
			int index = binarySearch(jobs, i);
			if (index != -1) {
				include += dp[index];
			}
			dp[i] = Math.max(include, dp[i - 1]);
		}
		return dp[rides.length - 1];
    }
}
