class Solution {
    public int numberOfWeakCharacters(int[][] properties) {
        int[] maxH = new int[100002];
        int count = 0;
        for(int[] point:properties){
            maxH[point[0]] = Math.max(point[1],maxH[point[0]]);
        }
        for(int i=100000;i>=0;i--){
            maxH[i] = Math.max(maxH[i+1],maxH[i]);
        }
        
        for(int[] point:properties){
            if(point[1]<maxH[point[0]+1])
                count++;
        }
        return count;
    }
}
