// Runtime: 1507 ms (Top 14.2%) | Memory: 218.14 MB (Top 11.2%)

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> free, busy; 
        for (int i = 0; i < servers.size(); ++i) {
            free.push(vector<long long>{servers[i], i});
        }
        vector<int> ans;
        long long time = 0;
        queue<int> task_queue;
        while (ans.size() < tasks.size()) { 
            // Bring all eligible tasks to task_queue.
            for (int i = ans.size() + task_queue.size(); i <= time && i < tasks.size(); ++i) {
                task_queue.push(tasks[i]);
            }
            // Bring all eligible servers to free queue.
            while (!busy.empty() && busy.top()[0] <= time) {
                auto& top = busy.top();
                free.push(vector<long long>{top[1], top[2]});
                busy.pop();
            }
            // If we have no servers, we cannot match until one of the servers becomes free.
            if (free.empty()) {
                time = busy.top()[0];
                continue;
            }
            while(!task_queue.empty() && !free.empty()) {
                // Now we just take the first task and first server as per defined priority and match the two.
                int task = task_queue.front(); 
                auto& top = free.top();
                ans.push_back(top[1]);
                busy.push(vector<long long>{time + task, top[0], top[1]});
                task_queue.pop();
                free.pop();
            }
            // Only increment time to receive new tasks once we have processed all tasks so far.
            if (task_queue.empty()) time++;
        }
        return ans;
    }
};