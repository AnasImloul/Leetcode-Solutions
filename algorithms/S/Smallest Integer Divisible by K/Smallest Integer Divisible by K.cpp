class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long n=1,res=1;
        while(n<k){
            n=n*10+1;
            res++;
        }
        if(n==k)
            return res;
        set<int> a;
        while(true){
            n%=k;
            if(n==0)return res;
            if(a.count(n)){
                break;
            }
            a.insert(n);
            n=n*10+1;
            res++;
        }
        return -1;
    }
};
