// Runtime: 177 ms (Top 67.53%) | Memory: 102.50 MB (Top 17.88%)

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        // Use a map to keep track of the last occurrence day for each task
        unordered_map<int, long long> lastOccurrence;
        
        // Initialize the current day to 0
        long long currentDay = 0;

        // Loop through each task in the list
        for(int task : tasks) {
            // If the task has been executed before
            if(lastOccurrence.find(task) != lastOccurrence.end()) {
                // Check if the space constraint is satisfied
                if(currentDay - lastOccurrence[task] <= space) {
                    // If not, move the currentDay ahead
                    currentDay = lastOccurrence[task] + space + 1;
                } else {
                    // If yes, just increment the current day
                    currentDay++;
                }
            } else {
                // If the task hasn't been executed before, simply increment the current day
                currentDay++;
            }

            // Update the last occurrence of the task
            lastOccurrence[task] = currentDay;
        }

        return currentDay;
    }
};

