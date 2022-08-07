class Solution {
public:
    int search(vector<int>& nums, int target) {
        
//         Easy Binary Search Approch 
//         Time : O(logn)
        
        int n = nums.size();
        int low = 0 , high = n-1;
        
        while(low<=high)
        {   
            int mid = (low+high)/2;
            if(nums[mid] == target)
            {
                return mid;
            
            }
            //moving to left side of the array
            
            if(nums[low] <= nums[mid]) //checking left side is sorted or not
            {
                if((target>=nums[low] && target<nums[mid]))   //  checking that our target is lie on the left side or not
                {
                    high = mid-1;
                    
                }
                else 
                {
                    low= mid+1;
                    
                }
            }
            else    //now moving to right side
            {
                if((target>nums[mid] && target <= nums[n-1]))  //Checking that the target is lie on the right side or not
                {
                    low = mid+1;
                    
                }
                else
                {
                    high = mid -1;
                }
            }
        }
        return -1;
    }
};
