class Solution {
    int mod = 1000000007;
    
    public int kadane(int[] a ){
        int curr = 0;
        int max = Integer.MIN_VALUE;
        for(int i: a )
        {
            curr+=i;
            if(curr<0 )
                curr =0;
            max = Math.max(max,curr );
            
        }
        
        return max%mod ;
    }
    public int kConcatenationMaxSum(int[] arr, int k) {
        
        int n = arr.length;
        if(k==1 ) 
            return kadane(arr);
        int[] temp = new int[2*n]; 
        for(int i=0;i<n;i++){
            temp[i]=arr[i];
            temp[n+i] =arr[i];
        }
        if(k==2 )
            return kadane(temp)%mod;
        
        long sum = 0;
        for(int i: arr) 
            sum+=i;
        
        if(sum>=0 )
            return (int)( (kadane(temp)%mod)+ ((sum%mod) * (k-2)%mod) %mod);
        else
            return (kadane(temp)%mod );
    }
}
