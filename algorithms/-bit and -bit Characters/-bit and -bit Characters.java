class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        return solve(0, bits, 0);
    }
    
    private boolean solve(int idx, int[] bits, int prev) { 
        if (idx == bits.length) return prev == 0;
		
        return prev>= 2 
			? solve(idx+1, bits, bits[idx])
			 : solve(idx+1, bits, (prev<<1) | bits[idx]);
    }
}
