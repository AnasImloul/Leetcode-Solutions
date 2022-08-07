class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //intiution 
        /*
        all the permutation has an increasing sequence of terms when traversing the array in a reverse order and when we find the index at which increasing sequence breaks and we swap it with the value slightly greater than that found on the traversal in a reverse order which is found on the right side of that index and finally reverse the array from the right side of that index to the end to get the smallest rank of the array 
        */
        
        int n = nums.size();
        int breakPointIndex ;
        
        //find the brakpoint index where the increasing sequence breaks
        for(int i = n -2 ; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                breakPointIndex = i;
                break;
            }
        }
        
        int smallestNoOnTheRightIndex ;
        
        //find the smallest no on the right index
        if(breakPointIndex < 0){
            reverse(nums.begin(), nums.end());
        }
        else {
            for(int i = n - 1; i > breakPointIndex; i--){
                if(nums[i] > nums[breakPointIndex]){
                    smallestNoOnTheRightIndex = i;
                    break;
                }
                
               
            }
             //swap the two values
                swap(nums[breakPointIndex], nums[smallestNoOnTheRightIndex]);
                
                //reverse the array to get the minimum rank of the array 
                reverse(nums.begin() + breakPointIndex + 1, nums.end());
        }
    }
};

