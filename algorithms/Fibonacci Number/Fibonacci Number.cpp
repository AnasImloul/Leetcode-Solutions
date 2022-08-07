class Solution {
public:
    int fib(int n) {
        double sqrt5 = 2.23606797749979;
        double expr1 = 1.61803398874989;
        double expr2 = -0.618033988749895;
        double res = (pow(expr1,n)-pow(expr2,n))/sqrt5;
        int result = (int)round(res);
        return result;
    }
};
