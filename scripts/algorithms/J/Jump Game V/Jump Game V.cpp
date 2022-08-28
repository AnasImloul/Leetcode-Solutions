// Runtime: 70 ms (Top 44.94%) | Memory: 14.9 MB (Top 51.98%)
class Solution {
    vector<int> dp;
    int countJumps(vector<int>& arr, int i, int d){
        if(dp[i]!=-1) return dp[i];
        int jumps = 0;
        int k = 1;
        while(k <= d && k + i < arr.size()){
            if(arr[k+i] < arr[i]){
                jumps = max(countJumps(arr, k+i, d)+1, jumps);
                k++;
            }
            else{
                break;
            }
        }
        k = 1;
        while(k <= d && i - k >= 0){
            if(arr[i] > arr[i - k]){
                jumps = max(countJumps(arr, i-k, d)+1, jumps);
                k++;
            }
            else{
                break;
            }
        }
        return dp[i] = jumps;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        dp.resize(arr.size(), -1);
        int maxJumps = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            maxJumps = max(countJumps(arr, i, d), maxJumps);
        }
        return maxJumps + 1;
    }
};