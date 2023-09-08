// Runtime: 18 ms (Top 72.0%) | Memory: 54.86 MB (Top 75.9%)

class Solution {
    public int eliminateMaximum(int[] dist, int[] speed) {
        
        int n = dist.length;
        
        int[] time = new int[n];
        
        for(int i = 0; i < n; i++){
            time[i] = (int)Math.ceil(dist[i] * 1.0 / speed[i]);
        }
        
        Arrays.sort(time);
        
        int eliminated = 0;
		
		// At i = 0, minute = 0 ( therefore, we can use i in place of minute )
        
        for(int i = 0; i < n; i++){
			 
            if(time[i] > i){  // At ith minute, eliminate the first monster arriving after ith minute
                eliminated++;
            }else{
                break; // Monster reached the city
            }
        }
        
        return eliminated;
    }
}