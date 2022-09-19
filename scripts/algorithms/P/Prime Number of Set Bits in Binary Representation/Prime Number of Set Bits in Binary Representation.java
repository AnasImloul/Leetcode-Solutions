// Runtime: 161 ms (Top 18.27%) | Memory: 63.5 MB (Top 16.98%)
class Solution {
     public int calculateSetBits(String s){
        int count=0;
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i)=='1') count++;
        }
        return count;
    }

    public boolean isPrime(int n){
        if (n==0 || n==1) return false;
        for (int i = 2; i <= n/2; i++) {
            if(n%i ==0 ) return false;
        }
// System.out.println(n+" - ");
        return true;
    }

    public int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            String b= Integer.toBinaryString(i);

            int n=calculateSetBits(b);

            if(isPrime(n)) count++;
        }
        return count;
    }
}