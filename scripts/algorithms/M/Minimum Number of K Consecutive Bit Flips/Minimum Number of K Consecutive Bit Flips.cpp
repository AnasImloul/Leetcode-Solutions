
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int flips = 0;                  // flips on current positions
        vector<int> flip(n+1,0);        // to set end pointer for a flip i.e i+k ->-1
        int ops = 0;                    // answer
        
        for(int i=0;i<n;i++){
            
            flips +=flip[i];            // update flips for current position
                                       
            // even flips on 1 okay
            if(nums[i]==1 && (flips)%2==0){
                continue;
            }
            
            // odd flips on 0 okay
            
            if(nums[i]==0 && (flips)%2!=0){
                continue;
            }
            
            // margin error as k bits flips is must
            
            if(i+k > n){
                return -1;
            }
            
            ops++;           //increment ans
            flips++;         // do flip at this position
            flip[i+k] = -1;  // set poiter where current flip ends
            
        }
        
        return ops;
        
    }
};

