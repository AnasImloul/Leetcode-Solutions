// Runtime: 8 ms (Top 7.86%) | Memory: 7.2 MB (Top 60.31%)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        int cnt = 0;
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=i+1 ; j<nums.size() ; j++){
                if(nums[i] == nums[j]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};