class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(begin(workers), end(workers));
        sort(begin(tasks), end(tasks));

        int lTasks = -1, rTasks = min(tasks.size(), workers.size()) - 1;

        while (lTasks < rTasks) {
            int midTasks = (lTasks + rTasks + 1) >> 1, t = midTasks;
            deque<int> dq;

            for (int w = workers.size() - 1, freePills = pills; t >= 0; t--) {
                if (dq.size() > 0 && dq.front() >= tasks.at(t)) {
                    dq.pop_front();
                } else if (w >= 0 && workers.at(w) >= tasks.at(t)) {
                    w--;
                } else if (freePills > 0) {
                    while (w >= 0 && workers.at(w) + strength >= tasks.at(t))
                        dq.push_back(workers.at(w--));

                    if (dq.size() == 0) break;
                    dq.pop_back(), freePills--;
                } else break;
            }

            t == -1 ? lTasks = midTasks : rTasks = midTasks - 1;
        }

        return lTasks + 1;
    }
};