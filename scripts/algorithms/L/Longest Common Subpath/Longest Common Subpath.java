// Runtime: 460 ms (Top 16.0%) | Memory: 73.80 MB (Top 56.0%)

class Solution {
    
    //mod 
    long mod = (long)(Math.pow(10,11) + 3);
    
    long p = 100003;
    
     long p_i[];
    
    public int longestCommonSubpath(int n, int[][] paths) {
        
        //min length will be 1 
        int min = 1;
        
        //max length will be the (path of min length) 
    
        int max = Integer.MAX_VALUE;
        
        for(int path[] : paths){
            max = Math.min(max,path.length);
        }
        
        //now we will pre calculate the the powers of base
        //and upto max only bcoz that's the longest subarray 
        //we are going to deal with
        p_i = new long[max + 1];
        
        p_i[0] = 1;
        
        for(int i=1;i<=max;i++){
            //mod multiplication
            p_i[i] = mulmod(p_i[i-1],p,mod);
        }
            
        int ans = 0;
        
        while(min <= max){
            
            int mid = (min + max) / 2;
            
            if(solve(mid,paths)){
                //if this length satisfies 
                //we are moving to right  
                //checking length greater than this
                ans = mid;
                min = mid + 1;
            }else{
                //else smaller
                max = mid - 1;
            }
            
        }
        
        return ans;
        
    }
    
    public boolean solve(int len,int paths[][]){
        
        Map<Long,Long> map = new HashMap<>();
        
        // now for each path we are going to calculate the 
        // hash value for each subpath of length -> len
        // and store the frequency of hash in map
        // and if for a hash value the frequency equals 
        // paths.length it means it exists in all path array
        // so return true
        
        for(int path[] : paths){
            
            long hash = 0l;
            
            // we are using a set for storing hash value of particular len for 
            // each path beacuse there is a possibility 
            // that a subpath repeats multiple times 
            // in a path so it directly updating in map
            // will lead to wrong count
            Set<Long> set = new HashSet<>();
            
            // hash is calculated as
            // let's say len is 3
            // (p^3 * (path[0]+1)) + (p^2 * (path[1]+1)) + (p^1 * (path[2] + 1))
            
            // now when we are moving forward 
            // and we need to update the hash value 
            // we can do it like 
            // delete (p^3 * (path[index-len]+1)) from prev_hash
            // so now the hash will become -> 
            // (p^2 * (path[1]+1)) + (p^1 * (path[2] + 1))
            // and then multiply prev_hash by p
            // (p^3 * (path[1]+1)) + (p^2 * (path[2] + 1))
            // now add (p^1 * (path[3]+1))
            // so hash becomes->
            //(p^3 * (path[1]+1)) + (p^2 * (path[2] + 1)) + (p^1 * (path[3]+1))
            
            //using this way we avoid calculating invmod
            //so easier to implement
            
            for(int i=0;i<len;i++){
                hash = (hash + mulmod(p_i[len-i],(path[i]+1),mod)) % mod;
            }
            
            set.add(hash);
            
            for(int i=len;i<path.length;i++){
                long new_hash = (hash - mulmod(p_i[len],path[i-len]+1,mod) + mod)%mod;
                new_hash = mulmod(new_hash,p,mod);
                new_hash = (new_hash + mulmod(p_i[1],path[i]+1,mod))%mod;
                hash = new_hash;
                set.add(new_hash);
            }
            
            // now for all the hash values in the set we will update the count 
            // in the map
            for(long hsh : set){
                map.put(hsh,map.getOrDefault(hsh,0l) + 1l);
                if(map.get(hsh) == paths.length){return true;}
            }
        }
        
        
        return false;
        
    }
     public long pow(long a,long b,int mod){
        
        long val = a*1l;
        
        long ans = 1l;
        
        while(b > 0){
            if((b&1) == 1){
                ans = mulmod(ans,val,mod);
            }
            val = mulmod(val,val,mod);
            b = b >> 1;
        }
        
        return ans % mod;
    }
    
    long mulmod(long a, long b,long mod)
    {
        return ((a%mod) * (b%mod)) % mod;
    }
    
   
    
}
