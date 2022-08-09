class Solution {
    /** Algorithm
        1. Brute force cannot be used because of the set size.
        2. Traverse the dominos and group & count them by min-max value.
           As pieces can be from 1 to 9, means their groups will be from 11 to 99.
            eg: [1,2] will be the same as [2,1]. Their value is 10 * (min(1,2)) + max(1,2)
                => 10 * 1 + 2 = 12.
            so pieces[12]++;
        3. After finishing traversing, iterate over the counted pieces and if the count is
          > 1, calculate the combinations of X by 2.
        4. The formula is n!/ (k! * (n-k)!)
           As n! can be very large, use the short version of it; (n * (n-1)) / 2. EG n= 40
           Eg:  40!         simplify this(divide by 38!) 39 * 40
              --------                                  ---------   
               2! * (38!)                                   2
        5. Return the total result      
    */
    public int numEquivDominoPairs(int[][] dominoes) {
        int[] pieces = new int[100];
        for (int[] domino : dominoes) {
            pieces[10 * Math.min(domino[0], domino[1]) + Math.max(domino[0], domino[1])]++;
        }
        int pairs = 0;
        for (int i = 11; i <= 99; i++) {
            if (pieces[i] > 1) {
                pairs += getCombinations(pieces[i]);
            }
        }
        
        return pairs;    
    }
    
    private int getCombinations(int n) {
        return (n * (n-1)) / 2;
    }
}
