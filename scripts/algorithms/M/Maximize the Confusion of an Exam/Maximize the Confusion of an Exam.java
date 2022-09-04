// Runtime: 98 ms (Top 6.64%) | Memory: 48.1 MB (Top 51.04%)

class Solution {

    // Binary Search + Sliding Window fixed

    public int maxConsecutiveAnswers(String answerKey, int k) {

        int start = 1 ;
        int end = answerKey.length();
        int max_length = 0 ;

        while(start <= end) {
            int mid = start+(end-start)/2 ;
            if(isMax(answerKey , k , mid)) {
                max_length = mid ;
                start = mid+1 ;
            }else {
                end = mid-1 ;
            }
        }

        return max_length ;
    }

    public boolean isMax(String answerKey , int k , int max_val) {

        int T_count = 0 ;
        int F_count = 0 ;

        int i = 0 ;
        int j = 0 ;

        while(j < answerKey.length()) {

            if(answerKey.charAt(j) == 'T') {
                T_count++ ;
            }else {
                F_count++ ;
            }

            if(j-i+1 == max_val) {

                if(Math.max(T_count, F_count)+k >= max_val) {
                    return true ;
                }

                if(answerKey.charAt(i) == 'T') {
                    T_count-- ;
                }else {
                    F_count-- ;
                }

                i++ ;
            }

            j++ ;
        }

        return false ;
    }
}
