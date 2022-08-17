class Solution {
public:
    int MOD = 1e9 + 7 ;
    int numWays(string s) {
        int ones = count(begin(s),end(s),'1') , n = s.size() ;
        if(ones % 3) return 0 ;
        if(!ones) return (((n-1) * 1LL * (n-2) * 1LL) / 2) % MOD ; /// n- 1 C 2
        
        int left = 0 , right = 0 , count = 0 , i = 0 ;
        while(count <= ones / 3){
            count += s[i++] == '1' ;
            if(count == ones/3) ++left ;
        }
        i = n - 1 , count = 0 ;
        while(count <= ones/3){
            count += s[i--] == '1' ;
            if(count == ones/3) ++ right ;
        }
        
        return (left * 1LL * right * 1LL) % MOD ;
    }
};
