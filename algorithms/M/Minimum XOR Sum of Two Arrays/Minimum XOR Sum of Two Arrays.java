

class Solution {
    Integer[][] cache;
    
    public int minimumXORSum(int[] nums1, int[] nums2) {
        int n = nums1.length;
        
        cache = new Integer[n][1 << n];

        return getMinXorSum(0, 0, nums1, nums2);
    }
    
    
    private int  getMinXorSum(int index, int mask, int[] nums1, int[] nums2){
        if(index == nums1.length) return 0;
        
        //retrieve from cache
        if(cache[index][mask] != null) return cache[index][mask];
        
        //find minimum         
        int minXorSum = Integer.MAX_VALUE;

        for(int i = 0; i < nums2.length; i++){
            if((mask >> i & 1) == 1) continue;
            
            int xorSum =  (nums1[index] ^ nums2[i]) + getMinXorSum(index + 1, mask | (1 << i), nums1, nums2);
            
            //update minimum xor sum
            minXorSum  = Math.min(xorSum, minXorSum);
        }
        
        //store in cache
        cache[index][mask] = minXorSum;
        
        return minXorSum;
    }
    
}
