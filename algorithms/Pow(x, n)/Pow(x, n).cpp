class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0) return 1;      //anything to the power 0 is 1
        
        if(x==1 || n==1) return x;  //1 to the power anything = 1 or x to the power 1 = x
        
        double ans = 1;
        
        long long int a = abs(n);   //since int range is from -2147483648 to 2147483647, so it can't store absolute value of -2147483648
        
        if(n<0){    //as 2^(-2) = 1/2^2
            if(a%2 == 0) ans = 1/myPow(x*x,a/2);
            else ans = 1/(x * myPow(x,a-1));
        }
        else{
            if(a%2 == 0) ans = myPow(x*x,a/2);
            else ans = x * myPow(x,a-1);
        }
        
        return ans;
        
    }
};
