// Runtime: 2 ms (Top 68.17%) | Memory: 41.1 MB (Top 69.67%)
class Solution {
    public boolean isUgly(int n) {
        if(n==0) return false; //edge case
        while(n!=1){
            if(n%2==0){
               n=n/2;
            }
            else if(n%3==0){
               n=n/3;
            }
            else if(n%5==0){
               n=n/5;
            }
            else{
                return false;
            }
        }
        return true;

    }
}