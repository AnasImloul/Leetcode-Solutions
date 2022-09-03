// Runtime: 23 ms (Top 55.70%) | Memory: 11.9 MB (Top 18.51%)
class Solution {
public:

    static bool cmp(vector<int>a, vector<int>b){

        for(int i = 1; i<a.size(); i++){
            if(a[i]!=b[i]){
                return a[i]>b[i];
            }
        }

        return a[0]<b[0];
    }

    string rankTeams(vector<string>& votes) {

        int noofteams = votes[0].size();
        string ans = "";
        vector<vector<int>>vec(noofteams, vector<int>(noofteams+1, 0));

        unordered_map<char, int>mp;
        for(int i = 0; i<votes[0].size(); i++){
            mp[votes[0][i]] = i;
            vec[i][0] = votes[0][i]-'a';
        }

        for(string x: votes){
            for(int i = 0; i<x.size(); i++){
                vec[mp[x[i]]][i+1]++;
            }
        }

        sort(vec.begin(), vec.end(), cmp);

        for(int i = 0; i<vec.size(); i++){
            ans.push_back(vec[i][0]+'a');
        }

        return ans;
    }
};