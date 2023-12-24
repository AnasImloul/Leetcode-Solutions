// Runtime: 0 ms (Top 100.0%) | Memory: 8.00 MB (Top 36.07%)

class Solution {
public:
    
    int next(vector<int>& nums, int i){
        int n = nums.size();
        return (n+nums[i]+i)%n;
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        // we can use slow and fast pointer to check whether there is loop or not
        for(int &num: nums)
            num %= n;
        for(int i=0;i<n;i++){
            int slow = i,
                fast = i;
            while(nums[slow]*nums[next(nums,fast)]>0 && nums[slow]*nums[next(nums,next(nums,fast))]>0){
                slow = next(nums,slow);
                fast = next(nums,next(nums,fast));
                if(slow==fast){
                    if(slow==next(nums,slow)) // single length
                        return false;
                    return true;
                }
            }
			/// DONOT TRAVERSE WHERE THERE IS NO PATH TO GET LOOP.
            int j = i;
            int val = nums[i];
            while (nums[j] * val > 0) {
                int nexx = next(nums,j);
                nums[j] = 0;
                j = nexx;
            }
        }
        
        return false;
    }
};
