// Runtime: 62 ms (Top 15.48%) | Memory: 19.7 MB (Top 56.49%)
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
// setting the ans to maximum value of int
        int ans = INT_MAX ;
        for(int i : nums){
        // checking if each value of nums is less than the max value
            if(abs(i) < abs(ans)){
                ans = i ; //check for the lesser value
            }
            else if(abs(i) == abs(ans)){
                ans = max (ans,i) ; // return the maximum in cases there are multiple answers
            }
        }
        return ans ;
    }
};