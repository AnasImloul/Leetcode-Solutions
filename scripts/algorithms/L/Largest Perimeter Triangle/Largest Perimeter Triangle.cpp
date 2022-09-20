// Runtime: 74 ms (Top 28.00%) | Memory: 21.8 MB (Top 71.53%)
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int res = 0;

        sort(nums.begin(),nums.end(),greater<int>());

        for(int i = 0;i < nums.size()-2;i++)
        {
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];

            if(a<b+c&&b<a+c&&c<b+a)
            {
                res = res+a+b+c;
                break;
            }
        }
        return res;
    }
};