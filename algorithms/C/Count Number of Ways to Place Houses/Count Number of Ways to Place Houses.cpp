class Solution {
public:
    typedef long long ll;
    ll mod = 1e9+7;
    int countHousePlacements(int n) {
        ll house=1, space=1;
        ll total = house+space;
        for(int i=2;i<=n;i++){
	        house = space;
	        space = total;
	        total = (house+space)%mod;
	    }
	    return (total*total)%mod;
    }
};
