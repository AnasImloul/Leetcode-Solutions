class Solution {
    public int reachNumber(int target) {
        int sum =0 ,steps = 0;
        if(target ==0) return 0;
        target = Math.abs(target);
        while(sum< target){
            sum+=steps;
            steps++;
        }
        
        while(((sum-target)%2!=0)){
            sum+=steps;
            steps++;
        }
        return steps-1;

    }
}
