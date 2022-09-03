// Runtime: 380 ms (Top 65.56%) | Memory: 102 MB (Top 63.00%)
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int,long long int> hash; long long int curday=0;
        for(int i=0;i<tasks.size();i++){
            if(hash.count(tasks[i])) curday=max(curday,hash[tasks[i]]);
            hash[tasks[i]]=curday+space+1;
            curday+=1;
        }
        return curday;
    }
};