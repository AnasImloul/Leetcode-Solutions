// Runtime: 19 ms (Top 30.25%) | Memory: 10.4 MB (Top 17.08%)
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n = words.size();
        vector<pair<string, string>>v;
        for(auto it:words) {
            string even = "";
            string odd = "";
            for(int i = 0;i<it.size();i+=2) even+=it[i];
            for(int i = 1;i<it.size();i+=2) odd+=it[i];
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            even+=odd;
            v.push_back({it, even});

        }

        map<string, int>m;
        for(auto it:v) {
            m[it.second]++;
        }

        return m.size();
    }
};