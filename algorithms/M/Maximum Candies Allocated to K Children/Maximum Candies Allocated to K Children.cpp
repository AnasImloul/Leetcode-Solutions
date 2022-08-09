class Solution {
public:
    bool canSplit(vector<int>& candies, long long k, long long mid) {
        long long split = 0;
        for(int i = 0; i < candies.size(); ++i) {
            split += candies[i]/mid;
        }   
        if(split >= k)
            return true;
        else
            return false;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for(int i = 0; i < candies.size(); ++i) {
            sum += candies[i];
        }
        long long start = 1, end = sum/k;
        long long ans = 0;
        while(start <= end) {
            long long mid = (start + end)/2;
            if(canSplit(candies, k, mid)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid-1;
            }
        }
        return ans;
    }
};
