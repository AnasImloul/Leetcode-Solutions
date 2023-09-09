// Runtime: 0 ms (Top 100.0%) | Memory: 7.93 MB (Top 70.9%)

static int x = []() {
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
return 0; }();

class Solution { // tc: O(n+m) & sc: O(n+m)
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<bool> rows(n,false),cols(m,false);
        for(auto index: indices){
            rows[index[0]] = rows[index[0]] ^ true;
            cols[index[1]] = cols[index[1]] ^ true;
        }
        
        int r(0),c(0);
        for(int i(0);i<n;i++){
            if(rows[i]) r++;
        }
        
        for(int i(0);i<m;i++){
            if(cols[i]) c++;
        }
        return r*(m-c) + c*(n-r); // (or) return (r*m + c*n - 2*r*c);
    }
};