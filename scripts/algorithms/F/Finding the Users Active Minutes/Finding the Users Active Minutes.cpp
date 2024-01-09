// Runtime: 209 ms (Top 72.33%) | Memory: 91.00 MB (Top 60.25%)

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,set<int>> map;
        vector<int> res(k,0);
        for(auto &log : logs){
            map[log[0]].insert(log[1]);
        }
        for(auto i : map){
            res[i.second.size()-1]++;
        }
        return res;
    }
};
