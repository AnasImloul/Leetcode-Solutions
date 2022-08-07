class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        if( nums[0] == target or nums.back() == target ) return true; 
        // this line is redundant it reduces only the worst case when all elements are same to O(1)
        
        const int n = nums.size();
        int l = 0 , h = n-1;
        while( l+1 < n and nums[l] == nums[l+1]) l++;

        // if all elements are same
        if( l == n-1){
            if( nums[0] == target ) return true;
            else return false;
        }
        
        // while last element is equal to 1st element
        while( h >= 0 and nums[h] == nums[0] ) h--;
        int start = l , end = h;
        
        // find the point of pivot ie from where the rotation starts
        int pivot = -1;
        while( l <= h ){
            int mid = l + (h-l)/2;
            if( nums[mid] >= nums[0] ) l = mid+1;
            else {
                pivot = mid;
                h = mid-1;
            }
        }
        
        
        if( pivot == -1 ) l = start , h = end; // if no pivot exits then search space is from start -e end
        else {
            if( target > nums[end] ) l = start , h = pivot-1; // search space second half
            else l = pivot , h = end; // search space first half
        }
        
        // normal binary search
        while ( l <= h ){
            int mid = l + (h-l)/2;
            if( nums[mid] > target ) h = mid-1;
            else if( nums[mid] < target ) l = mid+1;
            else return true;
        }
        
        return false;
        
    }
};
