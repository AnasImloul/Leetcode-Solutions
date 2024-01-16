// Runtime: 4 ms (Top 77.63%) | Memory: 50.10 MB (Top 66.67%)

class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        // A[i] + A[j] + i - j = (A[i]+i) + (A[j]-j)
        // think about dividing them into two parts
        // get the max of left part and right part, then add them 
        // to get the maximum score
        //
        //                 max(left)   + max(right)
        // maximum score = max(A[i]+i) + max((A[j]-j))

        /* example:
          i  0  1  2  3  4
          A [8, 1, 5, 2, 6], max = 0
          
            i=1,
                left  = A[0]+0 = 8
                right = A[1]-1 = 0
                => max = max(max=0, left + right=8)    = 8
                Before moving to i=2, we need to update left part by 
                comparing current left and right
                so ----> left = max(left=8, A[1]+1=2)  = 8
            i=2,
                left  = 8
                right = A[2]-2 = 3
                => max = max(max=8, left + right=11)   = 11
                so ----> left = max(left=8, A[2]+2=7)  = 8 
            i=3,
                left  = 8
                right = A[3]-3 = 1
                => max = max(max=11, left + right=9)   = 11
                so ----> left = max(left=8, A[3]+3=5)  = 8 
            i=4,
                left  = 8
                right = A[4]-4 = 2
                => max = max(max=11, left + right=10)  = 11
                so ----> left = max(left=8, A[4]+4=10) = 8            
            end loop
                max = 11
        */
        int N = A.length;
        int left = A[0]+0;
        int right = 0; 
        int max = 0;

        for (int i=1; i<N; i++){
            right = A[i]-i;
            max = Math.max(max, left+right);
            // before we move on, we need to update the state of left part
            // now our current right part will become left part in next round
            left = Math.max(left, A[i]+i); 
        }
        return max;
    }
}
