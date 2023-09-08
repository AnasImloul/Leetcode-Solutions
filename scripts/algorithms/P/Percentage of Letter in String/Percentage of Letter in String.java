// Runtime: 0 ms (Top 100.0%) | Memory: 40.55 MB (Top 34.5%)

class Solution {
    public int percentageLetter(String str, char letter) {
        int count=0;
        int n=str.length();
        for(int i=0;i<n;i++){
            if(str.charAt(i)==letter){

                count ++;
            }
        }
                 int per= (100*count)/n;
         return per;   
        
    }
}