class Solution {
public:
    int flip(int n){
        // given integer abc returns intger cba by going to a temporary string
        auto str = to_string(n);
        std::reverse(str.begin(), str.end());
        return atoi(str.c_str());
    }
       
    bool isInteger(double v){
        // checks if the double v represents an integer value
        double tmp;
        return std::modf(v, &tmp) == 0.0;
        // alternative less robust implementation
        // return  static_cast<double>(static_cast<long>(v)) == v;
    }
    
    int largestPalindrome(int n) {
        
        if (n == 1) return 9;
        
        const long max = pow(10, n);
        
        for (int z = 2; z < max -1; z++){
            const long left = max -z;
            const long right = flip(left);
            const double sqrt_term = z*z - 4*right;
           
		    // let's avoid generating nans applying the square root to negative numbers
            if (sqrt_term < 0.0){ continue; }
            
            const double root1 = 0.5*(z + sqrt(sqrt_term));
            const double root2 = 0.5*(z - sqrt(sqrt_term));
            
            if (isInteger(root1) || isInteger(root2)){
                return (max*left + right) % 1337;
            }
        }
		// This should never be reached so we don't really care about what we return in here
        return -1;
    }
};
