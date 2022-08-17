class Solution {
public:
    #define ll long long 
    int findNthDigit(int n) {
        if(n<=9) return n;
        ll i=1;
        ll sum=0;
        while(true){
            ll a=(9*pow(10,i-1))*i;
            if(n-a<0){
                break;
            } 
            else{
                sum+=9*pow(10,i-1);
                n-=a;
            }
            i++;
        }
        
        ll x=0;        
        ll mod=n%i;
        n=(n/i);
        n+=sum;
        if(mod==0) return n%10;
        else{
            n++;
            ll x=i-mod;
            while(x--){
                n/=10;
            }
        }
        return n%10;
    }
};
