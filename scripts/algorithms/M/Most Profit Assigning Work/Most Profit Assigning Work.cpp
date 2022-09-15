// Runtime: 157 ms (Top 36.41%) | Memory: 37.7 MB (Top 62.44%)
class Solution {
public:
    static bool cmp(pair<int,int>a, pair<int,int>b){
        if(a.first == b.first){
            return a.second<b.second;
        }

        return a.first>b.first;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0;
        vector<pair<int,int>>vp;
        for(int i = 0; i<profit.size(); i++){
            vp.push_back({profit[i], difficulty[i]});
        }
        sort(vp.begin(), vp.end(), cmp);
        sort(worker.begin(), worker.end(), greater<int>());

        //i is for traversing the vp and j is for traversing the worker
        int i = 0, j = 0;

        while(i<vp.size() and j<worker.size()){
            if(worker[j]>=vp[i].second){
                ans+=vp[i].first;
                j++;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};