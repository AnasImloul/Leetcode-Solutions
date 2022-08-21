// Runtime: 30 ms (Top 15.78%) | Memory: 13.4 MB (Top 27.79%)

class Solution {
public:
    static bool comp(pair<string, string> a, pair<string, string> b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector< pair<string, string> > letter_logs;
        vector<string> digit_logs;
        vector<string> ans;
        for(int i = 0; i < logs.size(); i++) {
            string identifier = "";
            for(int j = 0; j < logs[i].length(); j++) {
                if(logs[i][j] == ' ') {
                    if(logs[i][j+1] >= 'a' && logs[i][j+1] <= 'z')
                        letter_logs.push_back({identifier, logs[i].substr(j+1, logs[i].size() - j + 1)});
                    else
                        digit_logs.push_back(logs[i]);
                    break;
                } else {
                    identifier.push_back(logs[i][j]);
                }
            }
        }
        sort(letter_logs.begin(), letter_logs.end(), comp);
        for(auto it: letter_logs) {
            cout<<it.first + " " + it.second<<endl;
            ans.push_back(it.first + " " + it.second);
        }
        for(auto it: digit_logs) {
            cout<<it<<endl;
            ans.push_back(it);
        }
        return ans;
    }
};