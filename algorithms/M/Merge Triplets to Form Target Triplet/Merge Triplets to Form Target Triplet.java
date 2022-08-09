class Solution {
    public boolean mergeTriplets(int[][] triplets, int[] target) {

        boolean xFound = false, yFound = false, zFound = false;
                
        for(int[] triplet : triplets){
		
            //Current Triplet is target
            if(triplet[0] == target[0] && triplet[1] == target[1] && triplet[2] == target[2])return true;
            
            if(triplet[0] == target[0]){
                if(triplet[1] <= target[1] && triplet[2] <= target[2])
                    if(yFound && zFound)return true;
                    else xFound = true;
            }
            if(triplet[1] == target[1]){
                if(triplet[0] <= target[0] && triplet[2] <= target[2])
                    if(xFound && zFound)return true;
                    else yFound = true;
            }
            if(triplet[2] == target[2]){
                if(triplet[1] <= target[1] && triplet[0] <= target[0])
                    if(yFound && xFound)return true;
                    else zFound = true;
            }        
        }
        return xFound && yFound && zFound;
    }
}
