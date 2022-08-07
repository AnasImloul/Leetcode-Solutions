class Solution {
public:
    int mySqrt(int x) {
        int s = 0 , e = x , mid;
        
        while(s<e)
        {
            mid = s + (e-s)/2 ;
            if(e-s == 1)
                break ;
            long double sqr = (long double)mid *mid;
            if(sqr <= x)
                s = mid ;
            else
                e = mid - 1 ;
        }
        if(e*e <= x )
            return e ;
        else
            return s ;
    }
}; ```