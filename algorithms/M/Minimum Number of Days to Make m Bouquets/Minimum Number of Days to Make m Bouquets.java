class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        if(m*k > bloomDay.length) return -1;
        
        int low = Integer.MAX_VALUE, high = 0;
        for(int i:bloomDay){
            low = Math.min(low,i);
            high = Math.max(high,i);
        }
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(bloomDay,mid,m,k)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
    private boolean isPossible(int[] bloomDay,int maxDays,int m,int k){
        for(int i=0;i<bloomDay.length;i++){
            int count = k;
            while(i<bloomDay.length && bloomDay[i]<=maxDays){
                count--;
                if(count==0){
                    m--;
                    break;
                }
                i++;
            }
            if(m==0) return true;
        }
        return false;
    }
}
