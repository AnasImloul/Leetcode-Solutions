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
