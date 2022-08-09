class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> v;
        for(int i=0;i<ranges.size();i++){
            // making ranges
            v.push_back({i-ranges[i],i+ranges[i]});
        }
        // sorting the intervals
        sort(v.begin(),v.end());
        
        // to keep track from where we need to cover
        int uncovered = 0;
        int idx = 0;
        // number of ranges used
        int cnt = 0;
        
        // to check if its possible
        bool ok = true;
        
        // as long as we have not covered the garden
        while(uncovered<n){
            // we will try to cover the uncovered such that new uncovered is maximum possible
            int new_uncovered = uncovered;
            while(idx<n+1 && v[idx].first<=uncovered){
                new_uncovered = max(new_uncovered,v[idx].second);
                idx++;
            }
            // we have used one range
            cnt++;
            
            // it means we were not able to cover with ranges so not possible
            if(new_uncovered == uncovered){
                ok = false;
                break;
            }
            // updating uncovered for next iteration
            uncovered = new_uncovered;
        }
        if(ok) return cnt;
        return -1;
    }
};
