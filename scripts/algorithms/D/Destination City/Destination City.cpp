class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string ans;
        unordered_map<string, int> m;
        for(int i=0; i<paths.size(); i++){
            m[paths[i][0]]++;
            m[paths[i][1]]--;
        }
        for(auto city : m){
            if(city.second == -1) ans = city.first;
        }

        return ans;
    }
};