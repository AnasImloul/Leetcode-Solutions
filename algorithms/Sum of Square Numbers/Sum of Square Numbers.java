class Solution {
    public boolean judgeSquareSum(int c) {
        long left=0;
        long right=(int)Math.sqrt(c);
        while(left<=right)
        {
            if((left*left+right*right)==c)
                return true;
            else
            {
            if((left*left+right*right)>c)
                right=right-1;
                else
                    left=left+1;
            }
            
        }
        return false;
    }
}
