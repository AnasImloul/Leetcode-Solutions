public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int mask = 0;
        int smask = 0;
        int j = 0;
        int rev = 0;
        
        // basically we are checking that the number is set bit or not 
        // if the number is set bit then we are appending that to our main answer i.e, rev
        for(int i=31 ; i>=0 ; i--){
            mask = 1<<i;
            if((mask&n)!=0){
                smask = 1<<j;
                rev = rev|smask;
            }
            j++;
        }
        
        // Time Complexity : O(32 for int)
        // Space Complexity : O(1)
        return rev;
    }
}
