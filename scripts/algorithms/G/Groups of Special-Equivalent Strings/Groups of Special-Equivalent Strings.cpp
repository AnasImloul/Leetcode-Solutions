// Runtime: 15 ms (Top 43.19%) | Memory: 10.3 MB (Top 18.60%)
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