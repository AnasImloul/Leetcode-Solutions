// Runtime: 1 ms (Top 98.93%) | Memory: 44.50 MB (Top 58.72%)

class Solution {
    public boolean validUtf8(int[] data) {
         int cnt = 0;
        for(int d : data){
            if(cnt == 0){
                if((d>>5) == 0b110) cnt = 1;
               else if((d>>4) == 0b1110) cnt=2;
               else if((d>>3) == 0b11110) cnt=3;
               else if((d>>7) != 0) return false;
            }else{
                if((d>>6) != 0b10) return false;
                cnt--;
            }
        }
        return cnt == 0;
    }
}
