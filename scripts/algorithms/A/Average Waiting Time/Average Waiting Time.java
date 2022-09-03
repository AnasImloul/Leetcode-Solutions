// Runtime: 16 ms (Top 7.49%) | Memory: 101.1 MB (Top 30.84%)
class Solution {
    public double averageWaitingTime(int[][] customers) {
        double time = 0;
        double waitingTime = 0;

        for(int[] cust : customers){
            time = Math.max(cust[0],time);
            time = time + cust[1];
            waitingTime += (time - cust[0]);
        }

        return waitingTime/customers.length;
    }
}