// Runtime: 0 ms (Top 100.00%) | Memory: 41.8 MB (Top 34.98%)
class Solution {
    public int minCostToMoveChips(int[] position) {
        int even = 0;
        int odd = 0;
        for(int i=0;i<position.length;i++){
            if(position[i]%2==0){
                even++;
            }else{
                odd++;
            }
        }
        return Math.min(even,odd);
    }
}