class Solution {
private:
    bool isValid(vector<int>& tasks, vector<int>& workers, const int& MAX_TASKS, int pills, int strength){
        multiset<int> workersMultiset(workers.end() - MAX_TASKS, workers.end());
        for(int i = MAX_TASKS - 1; i >= 0; --i){
            auto it = workersMultiset.lower_bound(tasks[i]);
            if(it == workersMultiset.end()){
                pills -= 1;
                it = workersMultiset.lower_bound(tasks[i] - strength);
            }
            if(it == workersMultiset.end() || pills < 0){
                return false;
            }
            workersMultiset.erase(it);
        }
        return true;
    }
    
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        const int T = tasks.size();
        const int W = workers.size();
        
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        int l = 0;
        int r = min(T, W);
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValid(tasks, workers, mid, pills, strength)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r;
    }
};
