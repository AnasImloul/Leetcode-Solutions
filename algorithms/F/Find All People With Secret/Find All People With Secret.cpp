class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> res;
        set<int> ust;
        ust.insert(0);
        ust.insert(firstPerson);
        map<int,vector<pair<int,int>>> mp;
        for (auto &m : meetings) {
            mp[m[2]].push_back({m[0],m[1]});
        }
        for (auto &m : mp) {
            for (auto &v : m.second) { //front to back
                if (ust.count(v.first)) {
                    ust.insert(v.second);
                }
                if (ust.count(v.second)) {
                    ust.insert(v.first);
                }
            }
            for (auto it = m.second.rbegin(); it != m.second.rend(); ++it) { //back to front
                if (ust.count((*it).first)) {
                    ust.insert((*it).second);
                }
                if (ust.count((*it).second)) {
                    ust.insert((*it).first);
                }
            }
        }
        for (auto it = ust.begin(); it != ust.end(); ++it)
            res.push_back(*it);
        return res;
    }
};
