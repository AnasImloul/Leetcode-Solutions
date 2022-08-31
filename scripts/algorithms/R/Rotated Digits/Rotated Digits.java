// Runtime: 5 ms (Top 82.34%) | Memory: 39.1 MB (Top 97.40%)
class Solution {
    public int rotatedDigits(int n) {
        int ans=0;
        for(int i=1; i<=n; i++){
            int k = i;
            boolean bool1=true; boolean bool2=false;
            while(k>0){
                int m=k%10;
                if(m==3 || m==4 || m==7){ bool1=false; break; }
                else if(m==2 || m==5 || m==6 || m==9){ bool2=true; }
                k/=10;
            }
            if(bool1 && bool2){ ans++; }
        }
        return ans;
    }
}