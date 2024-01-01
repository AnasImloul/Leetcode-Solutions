// Runtime: 0 ms (Top 100.0%) | Memory: 8.80 MB (Top 37.04%)

class Solution {
public:
    double solve(vector<int>& arr,int n){
        double count = 0;
        for(int i = 0;i < arr.size();i++){
            count += arr[i];
            if(count >= n)
                return i;
        }
        return -1;
    }
    vector<double> sampleStats(vector<int>& count) {
        int mini = INT_MAX;
        int maxi = 0;
        double sum = 0.0;
        int d = 0;
        int mode = 0;
        for(int i = 0;i < count.size();i++){
            if(count[i] == 0)
                continue;
            mini = min(mini,i);
            maxi = max(maxi,i);
            sum += double(count[i])*i;
            d += count[i];
            if(count[mode] < count[i])
                mode = i;
        }
        vector<double>ans(5,0.0);
        ans[0] = mini;
        ans[1] = maxi;
        ans[2] = sum/d;
        ans[4] = mode;
        if(d%2 == 0){
            ans[3] = (solve(count,d/2) + solve(count,d/2+1))/2;
        }
        else
            ans[3] = solve(count,d/2+1);
        return ans;
    }
};
