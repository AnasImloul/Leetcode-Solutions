class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> res(k);
        unordered_map<int,unordered_set<int>> m;
        for(int i=0;i<logs.size();i++){
            m[logs[i][0]].insert(logs[i][1]);
        }
        unordered_map<int,int> uma;
        for(int i=0;i<logs.size();i++){
            uma[logs[i][0]] = m[logs[i][0]].size();
        }
        for(auto p : uma){
            res[p.second - 1]++;
            
        }
        return res;
    }
};
