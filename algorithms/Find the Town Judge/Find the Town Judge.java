class Solution {
    public int findJudge(int n, int[][] trust) {
        int[]trusting = new int[n+1];
        int[]trusted = new int[n+1];
        
        for(int i=0;i<trust.length;i++){
            int a = trust[i][0];
            int b= trust[i][1];
            
            trusting[a]++;
            trusted[b]++;
        }
        
        for(int i=1;i<n+1;i++){
            if(trusted[i] == n-1 && trusting[i] == 0){
                return i;
            }
        }
        
        return -1;
        
    }
}
