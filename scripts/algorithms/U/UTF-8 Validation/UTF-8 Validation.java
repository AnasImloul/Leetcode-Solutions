// Runtime: 1 ms (Top 100.00%) | Memory: 48.5 MB (Top 26.95%)
class Solution {
    public boolean validUtf8(int[] data) {
        return help(data,0);
    }

    public boolean help(int[] data,int index) {
        int n=data.length-index;
        if(n==0){
            return true;
        }
        int c0=count(data[index]);
        if(c0<0||c0>n){
            return false;
        }
        for(int i=index+1;i<index+c0;i++){
            if((data[i]&0b10000000)!=0b10000000){
                return false;
            }
        }
        return help(data,index+c0);
    }

    private int count(int a){
        if((a>>3)==0b11110){
            return 4;
        }else if((a>>4)==0b1110){
            return 3;
        }else if((a>>5)==0b110){
            return 2;
        }else if((a>>7)==0){
            return 1;
        }
        return -1;
    }
}