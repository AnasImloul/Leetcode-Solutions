//odd-even=odd
//even-odd=odd
class Solution {
    public int numOfSubarrays(int[] arr) {
        long ans=0;
        int even=0;
        int odd=0;
        
        long sum=0;
        
        for(int i=0;i<arr.length;i++){
            sum+=arr[i];
            
            if(sum%2==0){
                ans+=odd;
                even++;
            }else{
                ans+=even+1;
                odd++;
            }
        }
        
        return (int)(ans%(1000000007));
    }
}
