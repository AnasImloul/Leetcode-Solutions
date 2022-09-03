// Runtime: 3 ms (Top 94.98%) | Memory: 7.5 MB (Top 61.16%)
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int sum = 0;
        for(int j:jobs)
            sum += j;
        sort(jobs.begin(),jobs.end(),greater<int>());
        int l = jobs[0], r = sum;
        while(l<r){
            int mid = (l+r)>>1;
            vector<int> worker(k,0);
            if(dfs(jobs,worker,0,mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
    bool dfs(vector<int>& jobs, vector<int>& worker, int step, int target){
        if(step>=jobs.size())
            return true;
        int cur = jobs[step];
        // assign cur to worker i
        for(int i=0;i<worker.size();i++){
            if(worker[i] + cur <= target){
                worker[i] += cur;
                if(dfs(jobs,worker,step+1,target))
                    return true;
                worker[i] -= cur;
            }
            if(worker[i]==0)
                break;
        }
        return false;
    }
};