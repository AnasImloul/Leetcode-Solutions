// Runtime: 25 ms (Top 89.8%) | Memory: 44.90 MB (Top 30.5%)

class Solution {
    public int numberOfWays(String corridor) {
        int numSeats = 0, numPlants = 0;
        long dividers = 1;
        
        for(int i = 0; i < corridor.length(); ++i) {
            if(corridor.charAt(i) == 'S') numSeats += 1;
            if(numSeats == 2 && corridor.charAt(i) == 'P') numPlants += 1;
            if(numSeats == 3) {
                dividers *= (numPlants + 1);
                dividers %= 1000000007;
                numSeats = 1;
                numPlants = 0;
            }
        }
        
        if(numSeats < 2) return 0;
        return (int)dividers;
    }
}