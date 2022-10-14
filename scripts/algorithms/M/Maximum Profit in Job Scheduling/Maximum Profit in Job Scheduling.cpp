// Runtime: 150 ms (Top 93.74%) | Memory: 49.8 MB (Top 86.31%)
struct Task {
    int start, end, profit;
    Task(int s, int e, int p) : start(s), end(e), profit(p) {};
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        // sort by ascending end time
        vector<Task> tasks;
        for (int i = 0; i < n; i++) tasks.push_back(Task(startTime[i], endTime[i], profit[i]));
        auto cmp = [] (const Task& t1, const Task& t2) { return t1.end < t2.end; };
        sort(tasks.begin(), tasks.end(), cmp);

        vector<int> dp(n, 0);
        dp[0] = tasks[0].profit;
        for (int i = 1; i < n; i++) {
            // Why upper bound works?
            // [1] if start time i-th task >= end time j-th task, then i-th task can complete all previous tasks of j-th task
            // [2] dp[i] can be dp[i-1], dp[i] means the maximum profit from 0 to i-th, but it includes i-th task or not
            // [3] same end time diffrent profit cases -> because of [2], we have to find the last index among duplicate numbers
            int j = lastBound(i-1, tasks, tasks[i].start);
            dp[i] = max(dp[i-1], (j!=-1?dp[j]:0) + tasks[i].profit);
        }
        return dp[n-1];
    }
    // Time : O(Nlog(N) + Nlog(N))
    // Space : O(N)
    // lastBound from upperBound
    int lastBound(int end, vector<Task>& tasks, int target) {
        int lo = 0, hi = end;
        while (lo < hi) {
            int m = lo + (hi-lo)/2;
            if (tasks[m].end <= target) lo = m + 1;
            else hi = m;
        }
        if (tasks[lo].end > target) lo--;
        return lo;
    }
};