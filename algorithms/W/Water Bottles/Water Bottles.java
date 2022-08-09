class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int drinkedBottles = numBottles;
        int emptyBottles = numBottles;
        
        while(emptyBottles >= numExchange){
            int gainedBottles = emptyBottles / numExchange;
            
            drinkedBottles += gainedBottles;
            
            int unusedEmptyBottles = emptyBottles % numExchange;
            
            emptyBottles = gainedBottles + unusedEmptyBottles;
        }
        return drinkedBottles;
    }
}
