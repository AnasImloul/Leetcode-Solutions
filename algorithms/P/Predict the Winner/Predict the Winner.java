class Solution {
    public boolean PredictTheWinner(int[] nums) {
        return predictTheWinner(nums, 0, nums.length-1,true,0, 0);
    }
   private boolean predictTheWinner(int[] nums, int start,int  end, boolean isP1Turn, long p1Score, long p2Score){
        if(start > end){
            return p1Score >= p2Score;
        }

        boolean firstTry;
        boolean secondTry;
        if(isP1Turn){
             firstTry = predictTheWinner(nums, start +1 , end, false, p1Score + nums[start], p2Score);
             secondTry = predictTheWinner(nums, start, end-1, false, p1Score + nums[end], p2Score);

        }else{
            firstTry = predictTheWinner(nums, start +1 , end, true, p1Score, p2Score + nums[start]);
            secondTry = predictTheWinner(nums, start, end-1, true, p1Score , p2Score + nums[end]);

        }
        return isP1Turn ? (firstTry || secondTry) : (firstTry && secondTry);
    }
}
