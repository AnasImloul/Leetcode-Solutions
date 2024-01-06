// Runtime: 12 ms (Top 94.81%) | Memory: 8.60 MB (Top 91.56%)

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};        // 10 primes in total-> need to check lesser than 30 only!
unordered_map<int,int> primeMap,freq;       // primeMap is used for setting the relevant bit in the mask. 
int MOD=1e9+7;
int power(long long x, long long y, int p =  MOD)
{
    unsigned long long res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)  res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
class Solution {
private:
    int getMul(int mask,int num){               // returns 0 for invalid mask
        for(auto& p:primes){
            if(num%p==0){
                if(mask&(1<<primeMap[p]))   return 0;  
                num/=p;
                if(num%p==0)    return 0;    // can be divided by the same num twice hence is divisible by the square -> p*p
                mask|=(1<<primeMap[p]);
            }
        }
        return mask;
    }
    int construct(int prod_mask,vector<int>& nums,int idx){
        if(idx==nums.size())    return prod_mask!=0;
        
        int res=construct(prod_mask,nums,idx+1);
        
        int mask_when_multiplied=getMul(prod_mask,nums[idx]);   // can I add this number to the set?
        if(mask_when_multiplied!=0) res=(res+1ll*freq[nums[idx]]*construct(mask_when_multiplied,nums,idx+1))%MOD;
        
        return res;
    }
public:
    int squareFreeSubsets(vector<int>& nums) {
        freq.clear();   // clear the maps
        
        for(int i=0;i<10;i++)    primeMap[primes[i]]=i+1;       // set the locs of the prime Numbers (10 in total)
        for(auto& i:nums)   freq[i]++;
        
        set<int> st(nums.begin(),nums.end());
        nums.clear();       // num would only contain numbers greater than 1 and unique-> reqd for the recursion
        for(auto& x:st) if(x>1)    nums.push_back(x);
        
        int numberOfSets=construct(0,nums,0)%MOD;       // number of ways of creating non empty valid subsets without 1 
        
        int nonEmpty1sets=(power(2,freq[1])-1+MOD)%MOD;
        
        numberOfSets=(numberOfSets+1ll*numberOfSets*nonEmpty1sets%MOD+nonEmpty1sets)%MOD;    
        
        // if 1s are present then they can be used individually -> (2^n)-1 ways or each of these comb i.e.(2^n)-1 can be multiplied with the currently formed set
        return numberOfSets;
        
    }
};
