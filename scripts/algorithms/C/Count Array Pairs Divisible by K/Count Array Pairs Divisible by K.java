// Runtime: 282 ms (Top 52.2%) | Memory: 55.61 MB (Top 63.3%)

//The condition given to us is (a*b % k==0)
// So we can rewrite the above condition that if any factor of k is present in a and any other factor of k is present in b then their multiplication will be divisble by k

// so gcd(a,k) * gcd(b,k) % k==0 


class Solution {
    public long countPairs(int[] nums, int k) {
        long ans=0;
        HashMap<Integer,Integer> hm=new HashMap<>();
        for(int val:nums){
            int gcd1=gcd(val,k);
            
            for(int gcd2:hm.keySet()){
                if((long)gcd1*gcd2 % k==0){
                    ans+=hm.get(gcd2);
                }
            }
            
            hm.put(gcd1,hm.getOrDefault(gcd1,0)+1);
        }
        
        return ans;
    }
    
    //function to calculate gcd 
   
    public int gcd(int n1,int n2)
    {
        while(n1%n2!=0){
            int rem=n1%n2;
            n1=n2;
            n2=rem;
        }
        return n2;
    }
}