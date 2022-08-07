class Solution {
    public int countPrimes(int n) {
      boolean check[]=new boolean[n];int count=0;
        for(int i=2;i<n;i++){
            if(check[i]==false){
                count++;
                for(int j=i;j<n;j+=i){
                    check[j]=true;
                }
            }
        }
        return count;
    }
}