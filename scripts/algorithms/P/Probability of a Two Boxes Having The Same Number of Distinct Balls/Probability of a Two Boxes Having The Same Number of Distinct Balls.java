// Runtime: 77 ms (Top 48.15%) | Memory: 41.6 MB (Top 50.00%)
class Solution {
    double all = 0;
    public double getProbability(int[] balls) {
        double[] fact = new double[25];
        fact[0]=1;
        for (int i = 1; i <= 24; i++){
            fact[i]=i*fact[i-1];
        }
        int need = Arrays.stream(balls).sum()/2;
        return solve(0, 0, need, new int[balls.length], balls, fact)/all;
    }

    private double solve(int idx, int got, int need, int[] cur, int[] balls, double[] fact){
        if (need == got){
            int colors=0;
            double a = fact[need];
            double b = fact[need];
            for (int i = 0;i<cur.length;i++){
                if(cur[i]==balls[i]){
                    ++colors;
                }else if (cur[i]==0){
                    --colors;
                }
                a/=fact[cur[i]];
                b/=fact[balls[i]-cur[i]];
            }
            all+=a*b;
            return colors==0?a*b:0;
        }
        if (idx == balls.length||got>need){
            return 0;
        }
        double ans = 0;
        for (int i = 0; i <=balls[idx];i++){ // for this level of ball, try to take 0 to balls[idx]
            cur[idx]+=i;
            ans += solve(idx+1,got+i,need,cur,balls,fact);
            cur[idx]-=i;
        }
        return ans;
    }
}