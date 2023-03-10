
class Solution {
public:
    // int x;
    // bool static cmp(vector<int> &a,vector<int> &b){
    //     return a[x]>b[x];
    // }
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> v;
        for(int i = 0; i < score.size(); i++){
            v.push_back({score[i][k],i});
        }
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        for(int i = score.size()-1; i>=0; i--){
            ans.push_back(score[v[i][1]]);
        }
        return ans;
    }
};