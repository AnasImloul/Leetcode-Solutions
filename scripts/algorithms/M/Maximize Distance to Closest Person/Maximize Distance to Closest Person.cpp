// Runtime: 7 ms (Top 99.28%) | Memory: 17.6 MB (Top 26.54%)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> d;
        int cnt = -1, ans = 0;

        for(int i=0; i<seats.size(); i++) {
            cnt++;
            if(seats[i]) d.push_back(cnt), cnt = 0;
        }
        d.push_back(cnt);

        for(int i=0; i<d.size(); i++) {
            if(i > 0 && i < d.size() - 1) d[i] /= 2;
            ans = max(ans, d[i]);
        }

        return ans;
    }
};