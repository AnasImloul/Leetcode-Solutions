// Runtime: 573 ms (Top 17.9%) | Memory: 159.65 MB (Top 21.0%)

class Solution {
public:
    vector<int> stree;
    void update(int tidx, int s, int e, int idx, int val){
        if(s == e){
            stree[tidx] = val;
            return;
        }
        int mid = (s + e)/2;
        if(idx <= mid) update(2*tidx, s, mid, idx, val);
        else update(2*tidx+1, mid+1, e, idx, val);
        stree[tidx] = min(stree[2*tidx], stree[2*tidx+1]);
    }
    int query(int tidx, int s, int e, int l, int r){
        if(s > r or e < l) return INT_MAX;
        else if(s >= l and e <= r) return stree[tidx];
        int mid = (s + e)/2;
        int left = query(2*tidx, s, mid, l, r);
        int right = query(2*tidx+1, mid+1, e, l, r);
        return min(left, right);
    }
    int boxDelivering(vector<vector<int>>& boxes, int port, int box, int weigh) {
        int n = boxes.size();
        vector<long long> trips(n+1), pref(n);
        trips[0] = 0, pref[0] = boxes[0][1];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + boxes[i][1];
            if(boxes[i][0] != boxes[i-1][0]){
                trips[i] = trips[i-1] + 1;
            }
            else{
                trips[i] = trips[i-1];
            }
        }
        trips[n] = trips[n-1];
        vector<long long> dp(n);
        stree = vector<int> (4*n + 1, INT_MAX);
        update(1, 0, n-1, 0, 0);
        // dp[i] = dp[j] + (trips[i] - trips[j+1]) + 2
        for(int i=0;i<n;i++){
            // L nikalo ?
            int l = 0, r = i;
            while(l < r){
                int mid = (l + r)/2;
                long long tot = pref[i] - ((mid-1>=0)?pref[mid-1]:0);
                if(tot <= weigh and i-mid+1 <= box){
                    r = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            int mini = query(1, 0, n, l, i);
            dp[i] = mini + trips[i] + 2;
            update(1, 0, n, i+1, dp[i] - trips[i+1]);
        }
        return dp[n-1];
    }
};