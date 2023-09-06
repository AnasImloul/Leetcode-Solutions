// Runtime: 0 ms (Top 100.0%) | Memory: 39.52 MB (Top 21.5%)

class Solution {
    public int passThePillow(int n, int time) {
    //     int count=0;
    //     for(int i=1; i<=time; i++){
    //         if(i < n){
    //             count+=1;
    //         }
    //         if(i>n){
    //             count--;
    //     }
    // }
    //     return count;
        int cur=1;
        int d=1;
        int ela=0;
        while(ela < time){
            cur+=d;
            if(cur == n ||cur == 1){
                d=-d;
            }
            ela++;
        }
        return cur;
}
}