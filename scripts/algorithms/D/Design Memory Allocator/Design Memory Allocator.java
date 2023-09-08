// Runtime: 23 ms (Top 74.3%) | Memory: 44.52 MB (Top 41.8%)

class Allocator {
    private int[] memory; 
    
    public Allocator(int n) {
        memory = new int[n]; 
    }
    
    public int allocate(int size, int mID) {
        int cnt = 0; 
        for (int i = 0; i < memory.length; ++i) {
            if (memory[i] == 0) {
                if (++cnt == size) {
                    for (int ii = i; ii >= i-size+1; --ii) 
                        memory[ii] = mID; 
                    return i-size+1; 
                }
            } else cnt = 0; 
        }
        return -1; 
    }
    
    public int free(int mID) {
        int ans = 0; 
        for (int i = 0; i < memory.length; ++i) 
            if (memory[i] == mID) {
                ++ans; 
                memory[i] = 0; 
            }
        return ans; 
    }
}