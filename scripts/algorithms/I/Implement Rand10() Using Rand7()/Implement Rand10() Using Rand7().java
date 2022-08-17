/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    public int rand10() {
        int x = rand7();
        int y = rand7();
        
        int val = 7*(x-1) + y;
        
        if(val <= 10){
            return val;
        }else{
            return rand10();
        }
    }
}
