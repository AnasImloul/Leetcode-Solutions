class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        
        int lo = 1;
        int hi = (int)1e5;
        
        int ans = -1;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(isItPossible(mid, quantities, n)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        
        return ans;
    }
    
    private boolean isItPossible(int x, int[] quantities, int n){
        
        // isItPossible to distribute <= x products to each of the n shops
        for(int i=0; i<quantities.length; i++){
            
            int products = quantities[i];
            
            n -= Math.ceil(products/(x*1.0));
            
            if(n<0)     // means it requires more than n shops to distribute all products
                return false; 
        }
        
        return true; // distributed all products to exactly n shops
    }
}
