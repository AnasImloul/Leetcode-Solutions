// Runtime: 552 ms (Top 5.09%) | Memory: 109.6 MB (Top 89.15%)
//O(N) Time and O(1) Space - SLIDING WINDOW

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double ans = INT_MIN;

        int i = 0;
        int j = 0;
        int sum = 0;

        while(j<nums.size()){

            //calcs
            sum = sum+nums[j];

            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){

                //ans
                double nos = k*1.0;
                ans = max(ans, sum/nos);

                int v = nums[i];
                sum = sum - v;

                //SLIDE
                i++;
                j++;
            }
        }

        return ans;

    }
};