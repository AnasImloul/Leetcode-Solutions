class Solution {
    static boolean flag = false;   // If flag is true no more operations in recursion, directly return statement
    public boolean canCross(int[] stones) {
        int i = 0; // starting stone
        int k = 1; // starting jump
        flag = false; 
        return canBeCrossed(stones, k, i);
    }
    
    public boolean canBeCrossed(int[] stones, int k, int i){
        if(!flag){ // If flag is false 
        if(stones[i] + k == stones[stones.length - 1]){ // If frog do 'k' jump from current stone lands on last stones, no more recusive calls and return true
            flag = true;
            return true;
        }
		// If frog do 'k' jump from current stone crosses last stone or not able to reach next stone
		//return false
        if((stones[i] + k > stones[stones.length - 1]) || (stones[i]+k<stones[i+1])) return false;
        int temp = i+1; // identify which next stone frog can reach
		//Find untill which stone frog can jump 
		//So jump from current stone not greater than next possible stone exit loop
        while(stones[i]+k > stones[temp]) temp++;
		//If loop exited 2 condition possible
		//jump from current stone is reached next possible stone
		//or not
		
		//If next possible stone reached
		//then do all possible jumps from this stone 
		//the current stone is 'temp'
		//possible jumps are 'k-1', k, 'k+1'
        if(stones[i]+k == stones[temp]) return (canBeCrossed(stones, k+1, temp) || canBeCrossed(stones, k, temp) || canBeCrossed(stones,k-1,temp));
		
		//If next possible stone not reached means jump from the current stone can't reach any stone
		//hence return false
        else return false;
    }
        else return true;
    }
}