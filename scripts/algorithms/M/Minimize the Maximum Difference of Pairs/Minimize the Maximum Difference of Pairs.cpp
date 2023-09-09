// Runtime: 136 ms (Top 29.1%) | Memory: 81.31 MB (Top 5.2%)

class Solution {
public:
    bool helper(vector<int> &v,int m,int p) {
        int cnt = 0,mx = 0;
        for(int i = 1; i < v.size(); i += 1) {
            if(v[i] - v[i - 1] <= m) {
                i += 1;
                cnt += 1;
            }
        }
        return cnt >= p;
    }
    
    int minimizeMax(vector<int>& v, int p) {
        sort(v.begin(),v.end());
        int l = 0,r = v.back(), ans = -1;
        //0,6 --> m = 3
        while(r >= l) {
            int m = (l + r)/2;
            // cout<<"m : "<<m<<endl;
            if(helper(v,m,p)) {
                ans = m;
                r = m - 1;
            } else l = m + 1;
        }
        return ans;
    }
};