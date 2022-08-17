class Solution {
    public int minFlips(String s) {
        /*
        * Sliding Window Approach
        */
        
        
        int n = s.length();
        
        int mininumFlip = Integer.MAX_VALUE;
        
        int misMatchCount = 0;
        for(int i = 0; i < (2 * n); i++){
            
            int r = i % n;
            
            //add mis watch count in current window
            if((s.charAt(r) - '0') != (i % 2 == 0 ? 1 : 0)) misMatchCount++;
            
            //remove mismatch count which are not relvent for current window
            if(i >= n && (s.charAt(r) - '0') != (r % 2 == 0 ? 1 : 0)) misMatchCount--;
            
            
            //misMatchCount : when valid binary string start from 1
            //n - misMatchCount : when valid binary string start from 0
            if(i >= n - 1) mininumFlip = Math.min(mininumFlip, Math.min(misMatchCount, n - misMatchCount));
        }
        
        return mininumFlip;
    }
}

