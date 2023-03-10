class Solution {
    public int minMoves(int target, int maxDoubles) {
        int ans = 0;
        for(int i=0;i<maxDoubles;i++){
            if(target==1)break;
            
            if(target%2==0){
                ans+=1;
                target=(target)/2;
            }else{
                 ans+=2;
                target=(target-1)/2;
            }
        }
        return ans+target-1;
    }
}