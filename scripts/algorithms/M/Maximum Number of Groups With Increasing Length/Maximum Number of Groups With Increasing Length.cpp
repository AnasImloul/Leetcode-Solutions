// Runtime: 179 ms (Top 25.17%) | Memory: 132.00 MB (Top 12.59%)

class Solution {
public:
    
    bool check(vector<long long>& ps, int mid){
        int n=ps.size();
        for(int i=n-1; i>=0; i--){
            if(mid == 0) return true;
            long long s = (long long)mid*(long long)(mid+1)/2;
            if(s > ps[i]) return false;
            mid--;
        }
        return true;
    }
    
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        int n=usageLimits.size();
        int left=1, right=n;
        vector<long long> ps(n);
        for(int i=0; i<n; i++){
            if(i==0) ps[i] = usageLimits[i];
            else ps[i] = ps[i-1] + usageLimits[i];
        }
        int ans=1;
        while(left <= right){
            int mid = left + (right-left)/2;
            bool isPossible = check(ps, mid);
            if(isPossible){
                ans = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return ans;
    }
};
