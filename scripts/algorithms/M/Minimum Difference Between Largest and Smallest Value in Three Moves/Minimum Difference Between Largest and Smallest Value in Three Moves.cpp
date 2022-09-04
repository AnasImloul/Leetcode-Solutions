// Runtime: 112 ms (Top 79.01%) | Memory: 35.4 MB (Top 11.56%)
class Solution {
public:
    int minDifference(vector<int>& nums) {

        int n =nums.size();

        sort( nums.begin(), nums.end());

        if( n<5){
            return 0;

        }
        else return min({nums[n-4]- nums[0],nums[n-3]- nums[1] ,nums[n-2]-nums[2], nums[n-1]-nums[3]});

    }
};