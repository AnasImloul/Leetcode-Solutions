class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, pre = 0;
        for (int i = 0;i < bank.size(); i ++) {
            int n = count(bank[i].begin(), bank[i].end(), '1');
            if (n == 0) continue;
            ans += pre * n;;
            pre = n;
        }
        return ans;
    }
};
