// Runtime: 571 ms (Top 55.38%) | Memory: 115.7 MB (Top 27.93%)
class Solution {
public:
    vector<string> res;
    string s;
    int target, n;
    void solve(int it, string path, long long resSoFar, long long prev){
        if(it == n){
            if(resSoFar == target) res.push_back(path);
            return;
        }
        long long num = 0;
        string tmp;

        for(auto j = it; j < n; j++){
            if(j > it && s[it] == '0') break;

            num = num * 10 + (s[j] - '0');
            tmp.push_back(s[j]);

            if(it == 0) solve(j + 1, tmp, num, num);
            else{
                solve(j + 1, path + "+" + tmp, resSoFar + num, num);
                solve(j + 1, path + '-' + tmp, resSoFar - num, -num);
                solve(j + 1, path + '*' + tmp, resSoFar - prev + prev * num, prev * num);
            }
        }

    }
    vector<string> addOperators(string num, int target) {
        this -> target = target;
        s = num, n = num.size();

        solve(0, "", 0, 0);
        return res;
    }
};