// Runtime: 2 ms (Top 62.6%) | Memory: 40.11 MB (Top 61.2%)

class Solution {
    public int timeRequiredToBuy(int[] tickets, int k){
        int n= tickets.length;
        int time=0;
    
        if(tickets[k]==1) return k+1;
        while(tickets[k]>0){
            for(int i=0;i<n;i++){
                if(tickets[i]==0) continue;
                tickets[i]=tickets[i]-1;
                time++;
                if(tickets[k]==0) break;
            }
        }k--;
        return time;
    }
}
