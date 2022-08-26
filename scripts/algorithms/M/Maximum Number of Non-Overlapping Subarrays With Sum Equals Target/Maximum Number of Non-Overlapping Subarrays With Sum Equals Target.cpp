// Runtime: 392 ms (Top 40.92%) | Memory: 84.2 MB (Top 54.29%)
class Solution {
public:
    unordered_map<int,int> mpp ;
    int maxNonOverlapping(vector<int>& nums, int target) {

        int sum = 0 , ways = 0 , prev = INT_MIN ;
        mpp[0] = -1 ;
        for(int i = 0 ; i < nums.size() ; ++i ){
            sum += nums[i] ;
            if(mpp.find(sum - target) != end(mpp) and mpp[sum-target] >= prev ) ++ways , prev = i ;
            mpp[sum] = i ;
        }
        return ways ;
    }
};