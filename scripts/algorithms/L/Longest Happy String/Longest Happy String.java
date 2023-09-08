// Runtime: 0 ms (Top 100.0%) | Memory: 39.66 MB (Top 66.7%)

/*
The idea behid this problem
1. Here we start by taking the size as the sum of a, b, c.
2. Then we use 3 variables A, B, C to count the occurance of a, b, c.
3. Now we iterate until the size, and 
    -> Checks the largest number among a, b, c and whether the count < 2 or whther the count of other letters is 2 and there is still letters that can be added, then we append the letter, decrement from the total count of that particular letter and increase the occurance of that letter and set others back to zero.
    
4. Finally return the string.
*/
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        int totalSize = a + b + c;
        int A = 0;
        int B = 0;
        int C = 0;
        StringBuilder sb = new StringBuilder();
        for (int i=0; i<totalSize; i++) {
            // checks a is largest and its count still < 2 or B and C =2 and there are still a that can be added 
            if ((a>=b && a>=c && A<2) || (B==2 && a>0) || (C==2 && a>0)) {
                sb.append("a");
                a -= 1;
                A += 1;
                B = 0;
                C = 0;
            }
            // check b is largest and its count still < 2 or A and C = 2 and there are still b that cam be added
            else if ((b>=a && b>=c && B<2) || (A==2 && b>0) || (C==2 && b>0)) {
                sb.append("b");
                b -= 1;
                B += 1;
                A = 0;
                C = 0;
            }
            // checks c is largest and its count still < 2 or B and A = 2 and there are still c that can be added
            else if ((c>=a && c>=b && C<2) || (A==2 && c>0) || (B==2 && c>0)) {
                sb.append("c");
                c -= 1;
                C += 1;
                A = 0;
                B = 0;
            }
        }
        return sb.toString();
    }
}