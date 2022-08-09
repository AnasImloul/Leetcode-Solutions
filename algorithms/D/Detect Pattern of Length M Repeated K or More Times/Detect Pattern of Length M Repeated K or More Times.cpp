class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        unordered_map<string, vector<int>> ump;
        string num = "";
        for(int i = 0; i < arr.size(); ++i)
            num += to_string(arr[i]);
        for(int i = 0; i <= num.length() - m; ++i){
            string str = num.substr(i, m);
            ump[str].push_back(i);
        }
        for(auto it = ump.begin(); it != ump.end(); ++it){
            if(it->second.size() >= k){
                bool flag = true;
                for(int i = 1; i < it->second.size(); ++i){
                    if(it->second[i] - it->second[i - 1] < m)
                        flag = false;
                }
                if(flag == true)
                    return true;
            }
        }
        return false;
    }
};
