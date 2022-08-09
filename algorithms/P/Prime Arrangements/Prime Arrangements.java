class Solution {
     long mod = (long)(1e9+7);
    public int numPrimeArrangements(int n) {
        if(n==1){
            return 1;
        }
     
        boolean[] arr = new boolean[n+1];
        Arrays.fill(arr,true);
        arr[0]=false;
        arr[1]=false;
        
        for(int i=2;i<=Math.sqrt(n);i++){
            
            for(int j=i*i;j<=n;j+=i){
                if(arr[i]==false){
                    continue;
                }
                arr[j]=false;
            }
            
        }
       long prime = 0;
        long notPrime=0;
        for(int k=1;k<arr.length;k++){
            if(arr[k]==true){
                prime++;
            }
            else{
                notPrime++;
            }
        }

       long x = factorial(prime)%mod;
       long y = factorial(notPrime)%mod;
       long t = (x*y)%mod;
        return (int)t ;
        
    }
 
    public long factorial(long i){
        if(i<=1){
            return i;
        }
        return (i*(factorial(i-1)%mod))%mod;
    }
}
