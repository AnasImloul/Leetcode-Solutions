// Runtime: 8 ms (Top 77.22%) | Memory: 11.5 MB (Top 9.63%)
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        nums.push_back(0);
        sort(nums.begin(), nums.end());
        long sum = 0;
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            while((long)nums[i] > (long)(sum + 1)){
                ans++;
                sum += (long)(sum + 1);
                if(sum >= (long)n)
                    return ans;
            }
            sum += nums[i];
            if(sum >= (long)n)
                return ans;
        }
        while(sum < (long)n){
            ans++;
            sum += (long)(sum + 1);
        }
        return ans;
    }
};