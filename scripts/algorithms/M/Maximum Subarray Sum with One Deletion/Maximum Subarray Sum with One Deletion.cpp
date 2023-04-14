class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size(), curr, maxi = INT_MIN;
        vector<int> fw(n + 1, 0), bw(n + 1, 0);
        fw[0] = arr[0];
        maxi = max(maxi, fw[0]);
        
		// ith element denotes the maximum subarray sum with ith element as the last element
        for(int i = 1; i < n; ++i) {
            curr = max(arr[i], fw[i - 1] + arr[i]);
            maxi = max(maxi, curr);
            fw[i] = curr;
        }
        
		// similar to fw array, but in the backward direction
        bw[n - 1] = curr = arr[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            curr = max(arr[i], bw[i + 1] + arr[i]);
            maxi = max(maxi, curr);
            bw[i] = curr;
        }
        
        int res = INT_MIN;
        for(int i = 1; i < n - 1; ++i) {
            res = max(res, fw[i - 1] + bw[i + 1]);
        }
        return max(res, maxi);
    }
};