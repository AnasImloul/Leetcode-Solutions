// Runtime: 44 ms (Top 62.29%) | Memory: 74.7 MB (Top 66.20%)
class Solution {
    public int maxIceCream(int[] costs, int coins) {

        //Greedy Approach
        //a. sort cost in increasing order

        Arrays.sort(costs);

        int count = 0;
        for(int cost : costs){

            //b. check remainig coin is greater or equal than cuurent ice - cream cost
            if(coins - cost >= 0) {
                coins -= cost;
                count++;
            }
        }

        return count;
    }
}