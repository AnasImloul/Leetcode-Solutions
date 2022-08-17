class Solution {
    public boolean stoneGameIX(int[] stones) {
        Map<Integer, Integer> div3 = new HashMap<>();
        div3.put(0, 0);
        div3.put(1, 0);
        div3.put(2, 0);
        
        for(int stone : stones){
            div3.put(stone%3, div3.get(stone%3)+1);
        }
		// the count of 3's don't matter, only whether it is even or odd
        div3.put(0, div3.get(0)%2);
        
        
        if(div3.get(1) == 0 && div3.get(2) == 0){
            return false;
        }
        
        int smaller = Math.min(div3.get(1), div3.get(2));
        int larger = Math.max(div3.get(2), div3.get(1));
		// the combinations of 1's and 2's will work with each other in a complementary way. 
		// A pair of 1 and 2 makes modulo 3 to be 0
		// Three counts of 1 or 2 makes modulo 3 to be 0
		// so, we need only relative counts
        
        // if there are even 3's, then bob can't reverse alice's win
        // so, if all three digits chosen are the same then bob wins, but if there is another option then alice wins
        // [1,2,2,2] -> alice picks 1 and wins
        // [1,3,3,2] -> alice picks 1 or two and wins
        // [2,2,2] -> alice has to pick the third 2 and loses

        if(div3.get(0) == 0){
            return smaller != 0;
        }
        
        // all cases now have odd number of 3's, so result can be reversed
        
        // [1,1,1,1,3] -> 1,1,3,1 picked or 1,3,1,1 picked means alice wins
        // similar for 2 because the other number doesn't exist to make a %3 pair
        
        // if the difference of number counts is more than 2 then alice can always force bob
        // [3,1,2,2,2] -> 
		// [3,1,2,2,2,2] ->
        if(larger > smaller + 2){
            return true;
        }
        
        return false;
    }
}
