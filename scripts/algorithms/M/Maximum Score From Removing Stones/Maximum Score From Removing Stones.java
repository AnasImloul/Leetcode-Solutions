// Runtime: 0 ms (Top 100.0%) | Memory: 40.30 MB (Top 77.67%)

class Solution {
    public int maximumScore(int a, int b, int c) {
        // Make sure a <= b <= c
        if (a>b) return maximumScore(b,a,c);
        if (b>c) return maximumScore(a,c,b);
        
        // if sum of smallest numbers [a+b] is less than c, then we can a + b pairs with the c
        if (a+b<=c) return a+b;
        
        // if sum of smallest numbers is greater than c, then we can (a+b)/2 pairs after making c empty
        return c+(a+b-c)/2;
    }
}
