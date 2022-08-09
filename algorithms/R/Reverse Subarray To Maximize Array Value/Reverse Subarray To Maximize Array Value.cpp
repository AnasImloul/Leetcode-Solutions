class Solution {
public:

int maxValueAfterReverse(vector<int>& nums) {        
    int original =  0;        
    for(int i = 0 ;  i < nums.size() - 1 ; ++i) {
           original += abs(nums[i] - nums[i+1]);
    }       
    int ans  =  original;  
    int a1 = INT_MAX; 
    int a2 = INT_MAX;  
    int a3 = INT_MIN;   
    int a4 = INT_MIN; 
    int n = nums.size();
    for(int i = n - 2; i >= 1; --i) {
            int old = nums[i-1];
            int now = nums[i]; 
            if(i != n-2) {   
                int y1 = (nums[i-1] + nums[i]) - abs(old - now) - a1 + original;
                int y2 = (nums[i-1] - nums[i]) - abs(old - now) - a2 + original;
                int y3 = (nums[i] - nums[i-1]) - abs(old - now) + a3 + original;
                int y4 = -(nums[i-1] + nums[i]) - abs(old - now) + a4 + original;   
                ans =  max(max(y4, max(y1, max(y2,y3))), ans);  
            }
            a1 = min(a1, nums[i] + nums[i+1] + abs(nums[i] - nums[i+1])); 
            a2 = min(a2, nums[i] - nums[i+1] + abs(nums[i] - nums[i+1])); 
            a3 = max(a3, nums[i] - nums[i+1] - abs(nums[i] - nums[i+1])); 
            a4 = max(a4, nums[i] + nums[i+1] - abs(nums[i] - nums[i+1]));
            ans = max(ans, -abs(old - now) + abs(old - nums[nums.size()-1] + original)); 
    }
    for(int i = 1; i < n- 1; ++i) {
        ans = max(ans, -abs(nums[i] -nums[i+1]) + abs(nums[0] - nums[i + 1]) + original); 
    }
    return ans; 
}
