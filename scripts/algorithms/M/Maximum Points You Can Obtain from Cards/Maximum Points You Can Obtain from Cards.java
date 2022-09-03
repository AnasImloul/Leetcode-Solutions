// Runtime: 5 ms (Top 20.60%) | Memory: 66.5 MB (Top 16.04%)
class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int n = cardPoints.length;
        int[] totalSum = new int[n];
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += cardPoints[i];
            totalSum[i] = sum;
        }
        if(n==k){
            return sum;
        }
        int score =0;
        for(int i=0;i<=k;i++){
            int j = i+n-k-1;
            int subsum = 0;
            if(i==0){
                subsum = totalSum[j];
            }
            else{
                subsum = totalSum[j]-totalSum[i-1];
            }

            score = Math.max(score,sum-subsum);
        }
        return score;
    }
}