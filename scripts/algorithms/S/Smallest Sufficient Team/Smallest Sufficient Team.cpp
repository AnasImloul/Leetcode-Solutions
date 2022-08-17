class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        vector<int> mask(people.size(), 0);
        for(int i=0; i<people.size(); i++){
            for(int j=0; j<req_skills.size(); j++){
                for(int z=0; z<people[i].size(); z++){
                    if(people[i][z] == req_skills[j]){
                        mask[i] += (1<<j);
                        break;
                    }
                }
            }
        }
        vector<long long> dp(1<<req_skills.size(), INT_MAX);
        vector<vector<int>> save(1<<req_skills.size());
        dp[0] = 0;
        for(int i=0; i<(1<<req_skills.size()); i++){
            for(int j=0; j<mask.size(); j++){
                int new_mask = i&(i^mask[j]);
                if(dp[new_mask]+1<dp[i]){
                    dp[i] = dp[new_mask]+1;
                    save[i] = save[new_mask];
                    save[i].push_back(j);
                }
            }
        }
        return save[(1<<req_skills.size())-1];
        
    }
};