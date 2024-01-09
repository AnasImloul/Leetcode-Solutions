// Runtime: 10 ms (Top 99.69%) | Memory: 9.90 MB (Top 96.62%)

class Solution {
public:
    std::vector<int> smallestSufficientTeam(std::vector<std::string>& req_skills, std::vector<std::vector<std::string>>& people) {
        int n = req_skills.size();
        int m = people.size();
        
        std::unordered_map<std::string, int> skillToIndex;
        for (int i = 0; i < n; i++) {
            skillToIndex[req_skills[i]] = i;
        }
        
        std::vector<int> arr(m, 0);
        for (int i = 0; i < m; i++) {
            std::vector<std::string>& personSkills = people[i];
            int val = 0;
            for (const std::string& skill : personSkills) {
                val |= 1 << skillToIndex[skill];
            }
            arr[i] = val;
        }
        
        std::vector<bool> banned(m, false);
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int val = arr[i] | arr[j];
                if (val == arr[i]) {
                    banned[j] = true;
                }
                else if (val == arr[j]) {
                    banned[i] = true;
                }
            }
        }
        
        std::vector<int> ans;
        helper(0, n, arr, std::vector<int>(), banned, ans);
        
        return ans;
    }
    
private:
    void helper(int cur, int n, const std::vector<int>& arr, std::vector<int> team, const std::vector<bool>& banned, std::vector<int>& ans) {
        if (cur == (1 << n) - 1) {
            if (ans.empty() || team.size() < ans.size()) {
                ans = team;
            }
            return;
        }
        
        if (!ans.empty() && team.size() >= ans.size()) {
            return;
        }
        
        int zero = 0;
        while (((cur >> zero) & 1) == 1) {
            zero++;
        }
        
        for (int i = 0; i < arr.size(); i++) {
            if (banned[i]) {
                continue;
            }
            
            if (((arr[i] >> zero) & 1) == 1) {
                team.push_back(i);
                helper(cur | arr[i], n, arr, team, banned, ans);
                team.pop_back();
            }
        }
    }
};
