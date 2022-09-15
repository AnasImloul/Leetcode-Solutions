// Runtime: 1 ms (Top 88.45%) | Memory: 40.9 MB (Top 66.50%)
import java.util.*;
class Solution {
    public int trailingZeroes(int n) {
        int count=0;
        if(n<0) // edge case for negative no.s
            return -1;
        for(int i=5;i<=n;i*=5){
            count+=(n/i);
        }
        return count;
    }
}
/*
to find no of trailing zeroes
Step1: find no. of (2,5) pairs, that is no of trailing zeroes
            (Or)
    Property: [no. of 2s > no. of 5s]
Step 2: Find no. of 5s = floor(n/5);
        ex: 7! = 7/5 =1 (one trailing zero)
        But there is one more thing to consider, Numbers like 25,125,and so on have more than one-5
        ex: 26! = (26/5) +1 =6

Summary: So, first divide 'n' by 5 and remove all single 5s, then divide by 25 to remove extra 5s, and so on.
        Summarized Formula:
        [Trailing 0s in n!= floor(n/5)+floor(n/25)+floor(n/125)+....]
*/
