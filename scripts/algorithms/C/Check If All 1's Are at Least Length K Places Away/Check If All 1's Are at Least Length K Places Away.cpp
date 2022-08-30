// Runtime: 146 ms (Top 9.14%) | Memory: 57.5 MB (Top 92.55%)
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        bool once = true ;
        int x = 0 ;
        int diff = 0 ;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            if ( nums[i] == 1 and once ) {
                x = i ;
                once = false ;
            }
            else if ( nums[i] == 1 ) {
                diff = i-x ;
                if ( diff-1 < k ) return false ;
                x = i ;
            }
        }
        return true ;
    }
};