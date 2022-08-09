class Solution {
public:
    int solve(int n){
        
    int cnt=0;
    int v=0;
    while (n > 0) {
        v= n % 2;
        if(v==1)
            cnt++;
        n = n / 2;
        
    }

   return cnt;
        
}
    bool isprime(int n){
         if (n <= 1)
        return false;
 
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
    }
    
 
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for(int i=left;i<=right;i++){
            if(isprime(solve(i))){
                count++;
            }
        }
        return count;
    }
};
