
vector<string> moves;
int MOD = 1e9 + 7;
void fill(string s, int n, int p){
    if(n==0){
        moves.push_back(s);
        return;
    }
    for(int i=1; i<4; i++){
        if(p==i){
            continue;
        }
        string m = to_string(i);
        fill(s+m, n-1, i);
    }
    return;
}
class Solution {
public:
    vector<vector<int>>memo;
    int solve(int n, int lastIdx, int m){
        if (n == 0) return 1;
        int ret = 0;
        if (memo[n][lastIdx] != -1) return memo[n][lastIdx];
        string last = moves[lastIdx];
        for (int idx = 0; idx<moves.size(); idx++) {
            string move = moves[idx];
            bool same = false;
            for (int i = 0; i < m; i++) if (move[i] == last[i]) same = true;   
            if (!same) ret = (ret + solve(n - 1, idx, m)%MOD)%MOD;
        }
        return memo[n][lastIdx]= ret%MOD;
    }
    int colorTheGrid(int m, int n){
        moves.clear();
        fill("", m, -1);
        //cout<<moves.size()<<endl;
        memo.resize(n + 1, vector<int>(moves.size(), -1));
        int ret = 0;
        for (int idx = 0; idx < moves.size(); idx++)
            ret =  (ret + solve(n-1, idx, m)%MOD)%MOD;
        return ret;
    }
};

