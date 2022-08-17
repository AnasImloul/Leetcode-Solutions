class Solution {
    public int minimumOneBitOperations(int n) {
       
    int inv = 0; 
      
        //  xor until n becomes zero 
        for ( ; n != 0 ; n = n >> 1){ 
            
            inv ^= n;
            System.out.println(inv+" "+n);
        }
      
        return inv; 
    }
}
