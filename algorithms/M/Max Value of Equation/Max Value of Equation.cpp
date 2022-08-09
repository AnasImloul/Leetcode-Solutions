class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> dq;
        int res = -INT_MAX;
        for(auto point: points){
            while(!dq.empty() && point[0]-dq.front().second>k){
                dq.pop_front();
            }
            if(!dq.empty()){
                res = max(res, dq.front().first+point[0]+point[1]);
            }
            while(!dq.empty() && point[1]-point[0]>=dq.back().first){
                dq.pop_back();
            }
            dq.push_back({point[1]-point[0], point[0]});
        }
        return res;
    }
};